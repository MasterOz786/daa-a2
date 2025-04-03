
template<class T>
class LevelBawaGee {
public:
    static T*& inc(T*& arr, int& size, T newEle);
    static T*& dec(T*& arr, int& size);
    static const char* read(const char* fileName);
};