//Circular Queue Practice
#include <iostream>
using namespace std;

const int M=4;

template<class cQType>
class cirQueue{
    cQType cirQ[M];
    int tail;
    int head;
    int fullOrEmpty=0;
public:
    cirQueue():tail(-1), head(-1){}
    bool isFull();
    bool isEmpty();
    void enqueue(cQType);
    cQType dequeue();
    void display();
    int getHead(){return head;}
    int getTail(){return tail;}
};

template<class cQType>
bool cirQueue<cQType>::isFull(){
    if (fullOrEmpty==M)     return true;
    else return false;
}

template<class cQType>
bool cirQueue<cQType>::isEmpty(){
    if(fullOrEmpty==0)    return true;
    else return false;
}

template<class cQType>
void cirQueue<cQType>::enqueue(cQType x){
    if(isFull())
        cout<<"Queue dolu. eklenemedi\n";
    else {
        if (head==-1 && tail==-1){
            head=0;
        cirQ[++tail]=x;
        fullOrEmpty++;
    }
        else{
            cirQ[(++tail)]=x;
            fullOrEmpty++;
        }
        tail%=M;
}
}
template<class cQType>
cQType cirQueue<cQType>::dequeue(){
    cQType y;
    if(isEmpty()){
        cout<<"Queue bos, eleman cikarilamaz.\n";
        return 0;
    }
    else{
     fullOrEmpty--;
     y=cirQ[head];
     head=(head+1)%M;
     return y;
    }
}

template<class cQType>
void cirQueue<cQType>::display(){
    if(isEmpty()){
        cout<<"Queue bos. Gosterilecek eleman yok.\n";
    }
    else if(head>=tail){
        for(int i=tail; i<=head; i++)
            cout<<cirQ[i]<<'\t';
    }
    else{
        for(int i=head; i<=tail; i++)
            cout<<cirQ[i]<<'\t';
    }
    cout<<endl;
}

int main()
{
    cirQueue<int> nesne1CirQueue;
    //ilk durum; head ve tail değerlerini alalım:
    cout<<nesne1CirQueue.getTail()<<endl;   //-1
    cout<<nesne1CirQueue.getHead()<<endl;   //-1
    //iki eleman ekleyelim:
    nesne1CirQueue.enqueue(100);
    nesne1CirQueue.enqueue(200);
    //head ve taili kontrol edelim:
    cout<<nesne1CirQueue.getTail()<<endl;  //1: 2 eleman eklendi;
    cout<<nesne1CirQueue.getHead()<<endl;  //0: ilk  durumda -1 idi.
    //2 eleman daha ekleyelim:
    nesne1CirQueue.enqueue(300);
    nesne1CirQueue.enqueue(400);
    //head ve taili kontrol edelim:
    cout<<nesne1CirQueue.getTail()<<endl;   //3: toplam 4 eleman eklendi
    cout<<nesne1CirQueue.getHead()<<endl;   //0
    //içeriği görelim.
    nesne1CirQueue.display();   //100-200-300-400 gösterdi. Doğru
    //bir daha ekleyelim:
    nesne1CirQueue.enqueue(500);   //eklemeddi.
    //head ve taili de kontrol edelim:
    cout<<nesne1CirQueue.getTail()<<endl;    //3 :değişmedi
    cout<<nesne1CirQueue.getHead()<<endl;    //0
    //eleman çıkaralım:
    cout<<nesne1CirQueue.dequeue()<<endl;   //100
    //head ve tail'i kontrol edelim:
    cout<<nesne1CirQueue.getTail()<<endl;   //3
    cout<<nesne1CirQueue.getHead()<<endl;   //1
    //2 nesne çıkaralım:
    cout<<nesne1CirQueue.dequeue()<<endl;  //200
    cout<<nesne1CirQueue.dequeue()<<endl;  //300
    //head ve taili kontrol edelim:
    cout<<nesne1CirQueue.getTail()<<endl;   //3
    cout<<nesne1CirQueue.getHead()<<endl;   //3
    //kalan son elemanı da çıkaralım:
    cout<<nesne1CirQueue.dequeue()<<endl;   //400
    //head ve taili kontrol edelim:
    cout<<nesne1CirQueue.getTail()<<endl;   //3
    cout<<nesne1CirQueue.getHead()<<endl;   //0
    //Circular Queue bir tur doldurulup, tekrar elemanlar çıkarıldı. Eleman
    //ekleme ve çıkama sıraları doğru.
    //bir eleman ekleyip head ve taili kontrol edelim:
    cout<<nesne1CirQueue.dequeue()<<endl;        //queue boş eleman çıkarılmaz
    cout<<nesne1CirQueue.getTail()<<endl;       //3
    cout<<nesne1CirQueue.getHead()<<endl;       //0
    //elemanı çıkaralım: head ve taili kontrol edelim:
    nesne1CirQueue.enqueue(700);
    cout<<nesne1CirQueue.getTail()<<endl;
    cout<<nesne1CirQueue.getHead()<<endl;
    return 0;
}
