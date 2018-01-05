#include <iostream>
#include <string>
#include <fstream>

#pragma once

using namespace std;

template <typename ItemType>

class List {

private:

  struct Node {

    ItemType item;
    Node* next;
    Node* prev;
    int index;

    Node(const int _index, const ItemType _item) : item(_item), next(NULL), prev(NULL), index(_index) {}
  };

  Node* head;
  Node* tail;
  Node* e;
  Node* r;
  int size;
  
public:
  
  List() : head(NULL), tail(NULL), size(0) {}

  void insert(const int& index, const ItemType& item) {

    if (size == 0){
      e = new Node(index, item);
      head = e;
      tail = e;
      size++;
    }
    else{     
      r = new Node(index, item);
      if (r->index == head->index){
        r->prev = NULL;
        r->next = head;
        head->prev = r;
        head = r;
        size++;
        e = head->next;
        for (int i = 1; i < size; i++){
          e->index++;
          e = e->next;
        }
      }
      else if (r->index > tail->index){
        r->next = NULL;
        r->prev = tail;
        tail->next = r;
        tail = r;
        size++;
      }
      else{
        e = head;
        
        for (int i = 1; i < size; i++){
          e = e->next;
          if (e->index == r->index){
            r->next = e;
            r->prev = e->prev;
            e = e->prev;
            e->next = r;
            e = r->next;
            e->prev = r;
            size++;
            i = size;
          }
          
          
        }
        for (int i = index+1; i < size; i++){
          e->index++;
          e = e->next;
        }
      }           
    }
  }

  int print_(const ItemType& item) {
    int a = 0;
    e = head;
    for (int i = 0; i < size; i++){
      if (e->item == item){
        return e->index;
      }
      else{
        e = e->next;
        a++;
      }
    } 
    if (a == size){

      return -1;
    }
    else{
      return e->index;
    }
  }

  ItemType get_print(const int& index) {
    e = head;
    for (int i = 0; i < size; i++){
      if (e->index == index){
        return e->item;
      }
      else{
        e = e->next;
      }
    }
    return "";
  }
  
  int getsize() {

    return size;
  }
  
  void remove(const int& index) {
    if (size == 1){
      head = NULL;
      delete tail;
      tail = NULL;      
      size--;           
    }
    else{
      if (size != 0){

        if (index == head->index){
          e = head->next;
          e->prev = NULL;
          delete head;
          head = e;
          size--;
          for (int i = 0; i < size; i++){
            e->index--;
            e = e->next;
          }
        }
        else if (index == tail->index){
          e = tail->prev;
          e->next = NULL;
          delete tail;
          tail = e;
          size--;
        }
        else{
          remove2(index);
        }
      }
    }
  }
    
  void remove2(const int& index){
    e = head;
    for (int i = 2; i < size; i++){
      e = e->next;
      if (e->index == index){
        r = e->prev;
        r->next = e->next;
        r = e->next;
        r->prev = e->prev;
        delete e;
        e = r;
        size--;
        i = size;
      }
    }
    for (int i = index; i < size; i++){
      e->index--;
      e = e->next;
    }
  }

  void clear()
  {
    for (int i = 0; i < size; i++)
    {
      remove(i);
    }
  }
  void print(ofstream& out_file)  {
    
    for (int i = 0; i < size; i++)
    {
      out_file << "node " << i << ": " << get_print(i) << endl;
      
    }
  }

  ~List()
{
    e = head;

    while(e != NULL)
    {
        r = e->next;
        delete e;
        e = r;
    }

    head = NULL;
    tail = NULL;
    size = 0;
}

};