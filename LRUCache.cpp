#include<iostream>
#include<map>

using namespace std;

struct node
{
  int pg;
  struct node *next, *prev;
};

class LRUCache
{
  int size;
  int MAXSZ;
  struct node *head,*tail;
  public:
  LRUCache(int maxsize){
    MAXSZ=maxsize;
    size=0;
    head=new node();
    tail=new node();
    head->pg= tail->pg=-99;
    head->next= tail;
    head->prev= tail->next= NULL;
    tail->prev= head;
  }

  map<int, struct node *> m;
  void add_to_head(node * );
  void remove_from_list(node *);

  public:
  void get();
  void put (int pgno);
};
void LRUCache::add_to_head(struct node *n){
  n->next= head->next;
  n->prev= head;
  n->next->prev= n;
  head->next= n;
}

void LRUCache::remove_from_list(node *n){
  if (size==0)
    return;
  n->prev->next= n->next;
  n->next->prev= n->prev;
}

void LRUCache::put(int pgno){
  if (m.find(pgno)==m.end()){
    if (size >= MAXSZ)
    {
      m.erase(tail->prev->pg);
      remove_from_list(tail->prev);
    }
    else size++;
    struct node *nn = new node();
    nn->pg=pgno;
    add_to_head(nn);
    m.insert(make_pair(pgno,nn));
  }
  else{
    struct node *n= m[pgno];
    remove_from_list(n);
    add_to_head(n);
  }
}
void LRUCache::get(){
  struct node *temp=head;
  while (temp!=NULL ){
    if(temp->pg != -99)cout << temp->pg << " ";
    temp=temp->next;
  }
  cout << endl;
}

int main(){
  LRUCache lru(3);//declare
  //lru.get();
  lru.put(1);
  lru.put(2);
  lru.get();
  lru.put(1);
  lru.get();
  lru.put(3);
  lru.get();
  lru.put(4);
  lru.get();
  return 0;
}