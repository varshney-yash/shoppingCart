#include<iostream>
#include<vector>
#include "model.h"

//vector of type Product to store all products
vector<Product> allProducts={
    Product(1,"apple",80),
    Product(2,"banana",29),
    Product(3,"carrot",16),
    Product(4,"date",200),
    Product(5,"egg",100)
};

Product* chooseProduct(){
    //display the products;
    string productList;
    cout<<"In stock right now:\n";
    for(auto prod : allProducts){
        productList.append(prod.getItem());
    }
    cout<<productList<<endl;
    cout<<"***********************"<<endl;
    string choice;
    cin>>choice;

    for(int i=0;i<allProducts.size();i++){
        if(allProducts[i].getInitial()==choice){
            return &allProducts[i];
        }
    }
    cout<<"Product not in stock :("<<endl;
    return NULL;
}

bool checkout(Cart &cart){
    if(cart.isEmpty())
        return false;
    int amnt=cart.getAmount();
    cout<<"Enter payment amount in cash";
    int paid;
    cin>>paid;

    if(paid>=amnt){
        cout<<"Change "<<paid-amnt<<endl;
        cout<<"Thanks, come again!";
        return true;
    }

    cout<<"Please enter sufficient amount!"<<endl;
    return false;

}

int main(){
    // Product p(1,"apple",80);
    // cout<<p.getItem();
    // Item fruit(p,3);
    // cout<<endl<<fruit.getItemInfo();
    char choice;
    Cart cart;  
    while(true){
        cout<<"Select what you wanna do:-\n";
        cout<<"(a)dd item, (s)ee cart, (c)heckout" <<endl;
        cin>>choice;
        if(choice=='a'){
            //add items to cart
            Product* prod=chooseProduct();
            if(prod!=NULL){
                cout<<"Added "<<prod->getItem()<<"to your cart."<<endl;
                cart.addProduct(*prod);
            }
        }
        else if(choice=='s'){
            //see the cart
            cout<<"***************"<<endl;
            cout<<cart.seeCart();
            cout<<"***************"<<endl;
        }
        else{
            //checkout
            cart.seeCart();
            if(checkout(cart))
                break;
        }
    }
    return 0;
}
