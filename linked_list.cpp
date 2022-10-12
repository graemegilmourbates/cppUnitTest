/*
  Graeme Bates
  Linked List
*/
#include <iostream>
using namespace std;


template <typename T>
struct node{
  T key;
  node<T>* next=NULL;
  node<T>* previous=NULL;
};

template <class T>
linkedList<T>::linkedList(){
  root=NULL;
}

template <class T>
void linkedList<T>::push(T key, node<T>* n){
  if(n->next!=NULL){
    push(key, n->next);
  } else {
    n->next=new node<T>;
    n->next->key=key;
    n->next->previous=n;
  }
}

template <class T>
void linkedList<T>::push(T key){
  if(root==NULL){
    root=new node<T>;
    root->key=key;
    root->next=NULL;
    root->previous=NULL;
  } else {
    push(key, root);
  }
}

template <class T>
T linkedList<T>::pop(node<T>* n){
  if(n->next!=NULL){
    return pop(n->next);
  } else {
    T out=n->key;
    n->previous->next=NULL;
    delete n;
    return out;
  }
}

template <class T>
T linkedList<T>::pop(){
  if(root!=NULL){
    if(root->next!=NULL){
      return pop(root->next);
    } else {
      T out=root->key;
      delete root;
      root=NULL;
      return out;
    }
  } else {
    root=NULL;
    return 0;
  }
}

template <class T>
int linkedList<T>::length(){
  if(root!=NULL){
    int i=1;
    node<T>* current=root;
    while(current->next!=NULL){
      i++;
      current=current->next;
    }
    return i;
  } else { return 0; }
}

template <class T>
T linkedList<T>::get(int index){
  int i = 0;
  node<T>* current = root;
  while(i < index){
    current = current->next;
    i++;
  }
  return current->key;
}

template <class T>
linkedList<T> linkedList<T>::sub(int end){
  if(end<length()){
    linkedList<T> out=linkedList<T>();
    int i=0;
    while(i<end){
      out.push(get(i));
      i++;
    }
    return out;
  } else { return linkedList<T>(); }
}

template <class T>
linkedList<T> linkedList<T>::sub(int start, int end){
  if(end<length()){
    if(start<end){
      linkedList<T> out=linkedList<T>();
      int i=start;
      while(i<end+1){
        out.push(get(i));
        i++;
      }
      return out;
    } else { return linkedList<T>(); }
  } else { return linkedList<T>(); }
}

template <class T>
void linkedList<T>::print(){
  node<T>* current=root;
  while(current!=NULL){
    cout << current->key << endl;
    current=current->next;
  }
}

template <class T>
void linkedList<T>::destroy_list(){
  while(root!=NULL){
    pop();
  }
}

template <class T>
linkedList<T>::~linkedList(){
  destroy_list();
}

template <class T>
void linkedList<T>::operator+=(T key){
  push(key);
}

template <class T>
T& linkedList<T>::operator[](int index){
  if(index > length() || index < 0){
    throw invalid_argument("Index out of range.");
  }
  int i=0;
  node<T>* current=root;
  while(i<index){
    current=current->next;
    i++;
  }
  return current->key;
}

template <class T>
ostream& linkedList<T>::operator<<(ostream& os){
  int i=0;
  int l=length();
  while(i<l){
    os<< get(i) << " ";
    i++;
  }
  return os;
}

template <class T>
linkedList<T> mergeSort(linkedList<T> unsorted){
  int len=unsorted.length();
  linkedList<T> out=linkedList<T>();
  if(len>2){
    int split=len/2;
    linkedList<T> left=mergeSort(unsorted.sub(split));
    linkedList<T> right=mergeSort(unsorted.sub(split, len-1));
    int i=0;
    int j=0;
    while(i<left.length() || j<right.length()){
      if(!(i<left.length())){
        out.push(right.get(j));
        j++;
      } else if(!(j<right.length())){
        out.push(left.get(i));
        i++;
      } else {
        if(left.get(i) < right.get(j)){
          out.push(left.get(i));
          i++;
        } else {
          out.push(right.get(j));
          j++;
        }
      }
    }
  } else {
    if(len==1){
      out.push(unsorted.get(0));
    } else {
      if(unsorted.get(0)>unsorted.get(1)){
        out.push(unsorted.get(1));
        out.push(unsorted.get(0));
      } else {
        out.push(unsorted.get(0));
        out.push(unsorted.get(1));
      }
    }
  }
  return out;
}

template <class T>
void populateList(linkedList<T>& list, int length){
  int i=0;
  srand((unsigned) time(NULL));
  while(i<length){
    list+=rand();
    i++;
  }
}
