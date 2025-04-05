
struct Gadgets {
    int** arr = nullptr;
    int *productSizes = nullptr;
    int nTestCases;
};

template<class T>
class LevelBawaGee {
public:
    static T*& inc(T*&, int, T);
    static T*& dec(T*&, int);
    static Heap<T> read_q1(Heap<T>, const char*);
    static void read_q4(Gadgets*, const char*);
    static void print_gadgets_q4(Gadgets);
};