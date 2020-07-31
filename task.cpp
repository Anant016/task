#include <bits/stdc++.h>
using namespace std;

class item{
    string name;
    float price;//priceBeforetax
    float priceAfterTax;
    string category;
    bool import;
    public:
    item(string n,float p, string c,int i){
        name=n;
        price=p;
        category=c;
        import =i;
        priceAfterTax=p;
    }
    void printItemsBeforetax(){
        cout<<name<<" at price: "<<price<<". Category:"<<category;
        if(import)cout<<". Impoted."; 
        cout<<endl;
    }
    void printItemsAfterTax(){
        cout<<name<<" at price: "<<priceAfterTax<<". Category:"<<category;
        if(import)cout<<". Impoted."; 
        cout<<endl;
    }
    void salesTax(){
        int tax=0;
        if(category=="book" || category=="med" || category=="food"){}else{tax+=10;}
        
        if(import){
            tax+=5;
        }
        priceAfterTax=price+(price*tax/100);
    }
    float getPriceAfterTax(){
        return priceAfterTax;
    }
    float getPriceBeforeTax(){
        return price;
    }
};

int main() {
  vector<item> arr;
  float totaltax=0,totalamount=0;
  int n;
  cout<<"Enter No.of Items: \n";cin>>n;
  for(int i=0;i<n;i++){
      bool import;
      string name,category; //category -> book,food,med,others
      float price;
      cin>>name>>price>>category>>import;
      item ob1(name,price,category,import);
      arr.push_back(ob1);
  }
  
  //before tax  
  //   for(int i=0;i<arr.size();i++){
  //     arr[i].printItemsBeforetax();
  //   }
  
  //apply tax
  for(int i=0;i<arr.size();i++){
        arr[i].salesTax();
        arr[i].printItemsAfterTax();
        totalamount+=arr[i].getPriceAfterTax();
        totaltax+=arr[i].getPriceAfterTax()-arr[i].getPriceBeforeTax();
  }
  cout<<"Sales tax:"<<totaltax<<endl;
  cout<<"Total:"<<totalamount;
}


// Sample input 1 -
// 3
// book 12.49 book 0
// CD 14.99 others 0
// choclateBar 0.85 food 0

// Sample Output 1 -
// book at price: 12.49. Category:book
// CD at price: 16.489. Category:others
// choclateBar at price: 0.85. Category:food
// Sales tax:1.499
// Total:29.829


// Sample Input 2 -
// 2
// perfume 47.5 others 1
// choclate 10 food 1

// Sample Output 2 -
// perfume at price: 54.625. Category:others. Impoted.
// choclate at price: 10.5. Category:food. Impoted.
// Sales tax:7.625
// Total:65.125