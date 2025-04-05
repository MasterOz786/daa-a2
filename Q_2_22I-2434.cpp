/*
  FA-based Pattern Matching with Single-Char Wildcard Support (?)
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cctype>

#define DOMAIN 256 // asci

class FAEngine {
    std::vector<std::vector<int>> T;
    std::string pat;
    int len;

public:
    FAEngine(const std::string& p) : pat(p), len(p.size()) { construct(); }

    void construct() {
        T.assign(len + 1, std::vector<int>(DOMAIN, 0));
        for (int st = 0; st <= len; ++st)
            for (int ch = 0; ch < DOMAIN; ++ch) {
                if (st < len && (pat[st] == '?' || pat[st] == ch)) {
                    T[st][ch] = st + 1;
                } else {
                    std::string pre = pat.substr(0, st) + (char)ch;
                    for (int nxt = st; nxt > 0; --nxt) {
                        bool ok = true;
                        for (int k = 0; k < nxt; ++k) {
                            if (pat[k] != '?' && pat[k] != pre[pre.size() - nxt + k]) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) {
                            T[st][ch] = nxt;
                            break;
                        }
                    }
                }
            }
    }

    std::vector<int> scan(const std::string& txt) {
        std::vector<int> locs;
        int st = 0;
        for (int j = 0; j < txt.size(); ++j) {
            st = T[st][(unsigned char)txt[j]];
            if (st == len) locs.push_back(j - len + 1);
        }
        return locs;
    }

    std::string getP() const { return pat; }
    int sz() const { return len; }
};

std::string tolower_all(const std::string& input) {
    std::string r;
    for (auto c : input) r += tolower(c);
    return r;
}

// take input from command line arguments
int main(int argn, char** argv) {
    
    std::ifstream file(argv[1]);

    int P;
    file >> P; file.ignore();
    std::vector<FAEngine> matchers;

    while (P--) {
        std::string pat;
        std::getline(file, pat);
        matchers.emplace_back(tolower_all(pat));
    }

    int L; file >> L; file.ignore();

    for (int line = 1; line <= L; ++line) {
        std::string raw, norm;
        std::getline(file, raw);
        norm = tolower_all(raw);
        std::vector<std::string> hits;

        for (auto& m : matchers) {
            std::vector<int> pos = m.scan(norm);
            for (int idx : pos) {
                std::string word = raw.substr(idx, m.sz());
                hits.push_back(m.getP() + ": " + word + " at index " + std::to_string(idx));
            }
        }

        std::cout << "Matches in Line " << line << ":\n";
        if (hits.empty()) std::cout << "No match found\n";
        else for (auto& h : hits) std::cout << h << '\n';
    }

    file.close();
    return 0;
}
