
template <typename T>
struct node;

template <class T>
class linkedList{
  public:
    linkedList();
    ~linkedList();

    void push(T key);
    T pop();
    int length();
    linkedList<T> sub(int end);//Sub array from 0 to index
    linkedList<T> sub(int start, int end);//Sub array from a to b
    T get(int index);
    void print();
    void sort();

    void operator+=(T key);
    T& operator[](int index);
    ostream& operator<<(ostream& os);

  private:
    node<T>* root;
    void push(T key, node<T>* n);
    T pop(node<T>* n);
    void destroy_list();
};
