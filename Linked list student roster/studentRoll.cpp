#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node* temp = new Node;
  temp->s = new Student(s);
  temp->next = NULL;
  if(head == NULL){
    this->head = temp;
    this->tail = temp;
    return;
  }
  tail->next = temp;
  tail = temp;

}

std::string StudentRoll::toString() const {
  if(!head)
    return "[]";

  Node* temp = head;
  std::string str = "[";
  while(temp){
    str += temp->s->toString();
    if(temp != tail)
      str += ",";
    temp = temp->next;
  }
  str += "]";
  return str;
}



StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL; // initialize null values
  Node* temp = orig.head;
  while(temp){
    this->insertAtTail(*temp->s); // copy each node
    temp = temp->next;
  }
}

StudentRoll::~StudentRoll() {
  while(head!=NULL){
    Node* temp = head->next;
    delete head->s;
    delete head;
    head = temp;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  while(head!=NULL){
    Node* temp = head->next;
    delete head;
    head = temp;
  }
  tail = head = NULL;
  Node* temp = right.head;
  while(temp){
    this->insertAtTail(*temp->s);
    temp = temp->next;
  }


  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}




