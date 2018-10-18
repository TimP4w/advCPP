class ptrcounter {
    int n = 0;

    public:
    void increase() {
        n++;
    }

    void decrease() {
        n--;
    }

    int counter() {
        return n;
    }
};