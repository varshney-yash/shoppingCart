//Product, Item, Cart
#include<string>
#include<unordered_map>
using namespace std;

class Product{
    int pid;
    string pname;
    int pprice;
public:
    Product(){

    }
    Product(int id,string name,int price){
        //this-> not really required as I've named the vars differently
        this->pid=id; //unique
        this->pname=name;
        this->pprice=price;
    }

    string getItem(){
        return pname + ": Rs" + to_string(pprice) + "    ";
    }

    string getInitial(){
        return pname.substr(0,1);
    }
    friend class Item;
    friend class Cart;
};

class Item{
    Product product;
    int qty;

public:
    Item(){};
    Item(Product p,int q):product(p),qty(q){} //initialisation list
    int getItemPrice(){
        return qty+product.pprice;
    }

    string getItemInfo(){
        return to_string(qty) + " x " + product.pname + " Rs. " + to_string(qty*product.pprice) + " ";
    }
    friend class Cart;
};

class Cart{
    unordered_map<int,Item> items;

public:
    void addProduct(Product product){
        if(items.count(product.pid)==0){
            Item newItem(product,1);
            items[product.pid]=newItem;
        }
        else{
            items[product.pid].qty+=1;
        }
    }

    int getAmount(){
        int amnt=0;
         for(auto itemPair : items){
            auto item=itemPair.second;
            amnt+=item.getItemPrice();
        }
        return amnt;
    }

    string seeCart(){
        if(items.empty()){
            cout<<"You haven't added anything to the cart!"<<endl;
        }
        string itemizedList;
        int cart_total=getAmount();

        for(auto itemPair : items){
            auto item=itemPair.second;
            itemizedList.append(item.getItemInfo());
        }

        return itemizedList + "\n Total: Rs. " + to_string(cart_total) + "\n";
    }

    bool isEmpty(){
        return items.empty();
    }
};
