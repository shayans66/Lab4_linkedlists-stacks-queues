//
//  Dollar.hpp
//  Lab1_datastructs
//
//  Created by android on 7/3/20.
//  Copyright © 2020 android. All rights reserved.
//

#pragma once

#include <stdio.h>
#include <iostream>

#include <string>



class Dollar{
private:
    int whole_part;
    int fractional_part;
    
    std::string note_name, coin_name;
    
public:
    // Constructor to initialize Dollar object
    // with number of whole and fractional currency, note and coin name
    Dollar(){};
    Dollar(int whole_part, int fractional_part, std::string note_name, std::string coin_name);
    
    // Destructor
    ~Dollar();
    // Copy Constructor
    Dollar(Dollar &other);
    
    // Getter Methods
    int get_whole_part();
    int get_fractional_part();
    std::string get_note_name();
    std::string get_coin_name();
    
    // Setter Methods
    void set_whole_part(int w);
    void set_fractional_part(int f);
    void set_note_name(std::string n);
    void set_coin_name(std::string c);
    
    // Add 2 Dollars (or canadian dollars) together
    /*
     Pre: Dollars aren't added
     Post: Dollars are added
     Return: void
     */
    void operator+(Dollar& other);
    // Subtract dollar object 'other' with this
    /*
     Pre: Dollars aren't subtracted
     Post: Dollars are subtracted
     Return: void
     */
    void operator-(Dollar& other);
    // Compare 2 dollar objects
    /*
     Pre: Dollars aren't compared
     Post: Dollars are compared
     Return: true/false boolean saying if Dollars are equal or not
     */
    bool operator==(Dollar& other);
    /*
     Pre: Dollars aren't compared
     Post: Dollars are compared
     Return: true or false comparing dollar objects if 'this' is Greater than 'other'
     */
    bool operator> (Dollar& other);
    /*
     Pre: Dollars aren't compared
     Post: Dollars are compared
     Return: true or false comparing dollar objects if 'this' is less than than 'other'
     */
    bool operator< (Dollar& other);
    /*
     Pre: Dollars aren't output to an output stream object
     Post: Dollars are output to an output stream object
     Return: altered output stream object
     */
    friend std::ostream& operator<<(std::ostream& stream, Dollar& obj);
    
};

class CanadianDollar : public Dollar{
private:
    
    // attributes
    
    int whole_part;
    int fractional_part;
    
    std::string note_name, coin_name;
    
    double us_to_cad;
    
    
    
public:
    // Constructor to initialize CanadianDollar object
    // with number of whole and fractional currency, note and coin name
    CanadianDollar(int whole_part, int fractional_part, std::string note_name, std::string coin_name);
    ~CanadianDollar();
    
    // convert dollar to canadian dollar and reutrn canadian dollar object
    /*
     Pre: American dollar exists
     Post: American dollar exists along with converted Canadian dollar that has been generated
     Return: Newly generated converted Canadian Dollar
     */
    static CanadianDollar* convertToCanadianDollar(Dollar& dollar);
    // convert canadian dollar to dollar and return dollar object
    /*
     Pre: Canadian dollar exists
     Post: Canadian dollar exists along with converted American dollar that has been generated
     Return: Newly generated converted American Dollar
     */
    static Dollar* convertToDollar(CanadianDollar& cad);
    
    
};


class Wallet{
private:
    Dollar* dollars[2];
public:
    // Constructor for Wallet
    Wallet();
    // Destructor for Wallet
    ~Wallet();
    
    // Getter methods
    Dollar& getDollar(){
        return *dollars[0];
    }
    Dollar& getCanadianDollar(){
        return *(dollars[1]);
    }
    /*
     Pre: Dollar in dollars[0] not updated
     Post: Dollar in dollars[0] is newly updated by adding
     Return: void
     */
    void addDollar(Dollar& dollar);
    /*
     Pre: Dollar in dollars[0] not updated
     Post: Dollar in dollars[0] is newly updated by subtracting
     Return: void
     */
    void subtractDollar(Dollar& dollar);
    
    /*
     Pre: Dollar in dollars[1] not updated
     Post: Dollar in dollars[1] is newly updated
     Return: void
     */
    void addCanadianDollar(Dollar& canadianDollar);
    /*
     Pre: Dollar in dollars[1] not updated
     Post: Dollar in dollars[1] is newly updated
     Return: void
     */
    void subtractCanadianDollar(Dollar& canadianDollar);
    
    /*
     Pre: Parameter dollar and dollar in dollars[0] not compared
     Post: Are compared
     Return: Boolean saying if the dollar in dollars[] is greater
     */
    bool isDollarGreater(Dollar& dollar);
    /*
     Pre: Parameter dollar and dollar in dollars[1] not compared
     Post: Are compared
     Return: Boolean saying if the dollar in dollars[] is greater
     */
    bool isCanadianDollarGreater(CanadianDollar& canadianDollar);
    
};


//
//  Dollar.cpp
//  Lab1_datastructs
//
//  Created by android on 7/3/20.
//  Copyright © 2020 android. All rights reserved.
//


#include <stdio.h>
#include <iostream>

#include <string>



#define US_TO_CAD 1.36;

// Constructor to initialize Dollar object
// with number of whole and fractional currency, note and coin name
Dollar::Dollar(int whole_part, int fractional_part, std::string note_name, std::string coin_name){
    this->whole_part = whole_part;
    this-> fractional_part = fractional_part;
    
    this->note_name = note_name;
    this->coin_name = coin_name;
    
    
}


Dollar::~Dollar(){}
// Copy Constructor
Dollar::Dollar(Dollar &other){
    whole_part = other.get_whole_part();
    fractional_part = other.get_fractional_part();
    this->note_name = other.get_note_name();
    this->coin_name = other.get_coin_name();
}

// Getters
int Dollar::get_whole_part(){ return this->whole_part; }
int Dollar::get_fractional_part(){ return this->fractional_part; }
std::string Dollar::get_note_name(){ return this->note_name; }
std::string Dollar::get_coin_name(){ return this-> coin_name; }


// Setters
void Dollar::set_whole_part(int w){ this->whole_part = w; }
void Dollar::set_fractional_part(int f){ this->fractional_part = f;}
void Dollar::set_note_name(std::string n){ this->note_name = n;}
void Dollar::set_coin_name(std::string c){ this->coin_name = c;}

// Operator Overloading
// Adding
void Dollar::operator+(Dollar& other){
    this->whole_part += other.whole_part;
    this->fractional_part += other.fractional_part;
    while(this->fractional_part >= 100){
        ++this->whole_part;
        this->fractional_part -= 100;
    }
}
// Subtracting
void Dollar::operator-(Dollar& other){
    this->whole_part -= other.whole_part;
    this->fractional_part -= other.fractional_part;
    if(this->whole_part < 0)
        this->whole_part = 0;
    if(this->fractional_part < 0)
        this->fractional_part = 0;
}
// Compare 2 dollar objects
bool Dollar::operator==(Dollar& other){
    return whole_part == other.get_whole_part() &&
    fractional_part == other.get_fractional_part();
}
// Compare Dollar objects to see if 'this' is Greater than 'other'
bool Dollar::operator> (Dollar& other){
    if ( !(this->whole_part == other.whole_part))
        return this->get_whole_part() > other.get_whole_part();
    return this->get_fractional_part() > other.get_fractional_part();
    
    
}
// Compare Dollar objects to see if 'this' is less than 'other'
bool Dollar::operator< (Dollar& other){
    if ( !(this->whole_part == other.whole_part))
        return this->get_whole_part() < other.get_whole_part();
    return this->get_fractional_part() < other.get_fractional_part();
    
}
// output operator overload
std::ostream& operator<<(std::ostream& stream, Dollar& obj){
    
    stream <<  obj.whole_part << "." << obj.fractional_part;
    
    return stream;
}


// Constructor to initialize CanadianDollar object
// with number of whole and fractional currency, note and coin name
CanadianDollar::CanadianDollar(int whole_part, int fractional_part, std::string note_name, std::string coin_name) : Dollar(whole_part, fractional_part,  note_name, coin_name) {
    // 1 USD = 1.36 CAD
    this->us_to_cad = US_TO_CAD;
}
CanadianDollar::~CanadianDollar(){}


// convert dollar to canadian dollar and reutrn canadian dollar object
CanadianDollar* CanadianDollar::convertToCanadianDollar(Dollar& dollar){
    
    int whole, frac;
    whole = dollar.get_whole_part() * US_TO_CAD;
    frac = dollar.get_fractional_part() * US_TO_CAD;
    
    return new CanadianDollar(whole, frac, "Loonie", "Mint");
}

// convert canadian dollar to dollar and return dollar object
Dollar* CanadianDollar::convertToDollar(CanadianDollar& cad){
    int whole, frac;
    whole = cad.get_whole_part() / US_TO_CAD;
    frac = cad.get_fractional_part() / US_TO_CAD;
    
    return new Dollar(whole, frac, "Dollar", "Cent");
    
}

Wallet::Wallet(){
    dollars[0] = new Dollar(0, 0, "Dollar", "Cent");
    dollars[1] = new CanadianDollar(0, 0, "Loonie", "Mint");
}
Wallet::~Wallet(){}

void Wallet::addDollar(Dollar& dollar){
    dollars[0]->set_whole_part( dollars[0]->get_whole_part() + dollar.get_whole_part() );
    dollars[0]->set_fractional_part( dollars[0]->get_fractional_part()+ dollar.get_fractional_part() );
    
    
}
void Wallet::subtractDollar(Dollar& dollar){
    dollars[0]->set_whole_part( dollars[0]->get_whole_part() - dollar.get_whole_part() );
    dollars[0]->set_fractional_part( dollars[0]->get_fractional_part() -
                                    dollar.get_fractional_part() );
}

void Wallet::addCanadianDollar(Dollar& canadianDollar){
    dollars[1]->set_whole_part( dollars[1]->get_whole_part() + canadianDollar.get_whole_part() );
    dollars[1]->set_fractional_part( dollars[1]->get_fractional_part()+ canadianDollar.get_fractional_part() );
}
void Wallet::subtractCanadianDollar(Dollar& canadianDollar){
    dollars[1]->set_whole_part( dollars[1]->get_whole_part() - canadianDollar.get_whole_part() );
    dollars[1]->set_fractional_part( dollars[1]->get_fractional_part() - canadianDollar.get_fractional_part() );
}

bool Wallet::isDollarGreater(Dollar& other){
    if ( !(dollars[0]->get_whole_part() == other.get_whole_part()))
        return dollars[0]->get_whole_part() > other.get_whole_part();
    return dollars[0]->get_fractional_part() > other.get_fractional_part();
    
}
bool Wallet::isCanadianDollarGreater(CanadianDollar& other){
    if ( !(dollars[0]->get_whole_part() == other.get_whole_part()))
        return dollars[0]->get_whole_part() < other.get_whole_part();
    return dollars[0]->get_fractional_part() < other.get_fractional_part();
    
}


