#include<iostream>
#include"reclists.hpp"
#include"solutions.hpp"

int main()
{
/*
    std::cout << "Enter a list: ";
    list p = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p);
    std::cout << "The number of nodes at the top level of the input list is: "
        << numNodesAtTheTopLevel(p) << std::endl;

    //testing my functions
    std::cout << "-----Testing is_lat-----" << std::endl;
    std::cout << "Enter the list (a b c d e f): ";
    list a = read_list();
    std::cout << "Enter the list (a b () d e f): ";
    list b = read_list();
    write_list(a);
    if (is_lat(a)) { std::cout << "is all atoms" << std::endl; };
    if (!is_lat(a)) {std::cout << "is not all atoms" << std::endl; };
    write_list(b);
    if (is_lat(b)) { std::cout << "is all atoms" << std::endl; };
    if (!is_lat(b)) { std::cout << "is not all atoms" << std::endl; };

    std::cout << "-----Testing member-----" << std::endl;
    std::cout << "Enter an atom: ";
    list c = read_list();
    std::cout << "Enter the list (a b c d): " << std::endl;
    list e = read_list();
    if (member(c, e)) {std::cout << "is member" << std::endl; };
    if (!member(c, e)) {std::cout << "is not member" << std::endl; };
    std::cout << "Enter another atom: ";
    list d = read_list();
    if (member(d, e)) {std::cout << "is member" << std::endl; };
    if (!member(d, e)) {std::cout << "is not member" << std::endl; };

    std::cout << "-----Testing last-----" << std::endl;
    std::cout << "Enter the list (a b c d e f): ";
    list f = read_list();
    list g = last(f);
    std::cout << "Last element is f: ";
    write_list(g);

    std::cout << "-----Testing list_pair-----" << std::endl;
    std::cout << "Enter the list (a b c): ";
    list h = read_list();
    std::cout << "Enter the list (d e f): ";
    list i = read_list();
    std::cout << "The paired list is: ";
    list j = list_pair(h, i);
    write_list(j);
    std::cout << "-----Testing firsts-----" << std::endl;

    std::cout << "-----Testing firsts-----" << std::endl;
    std::cout << "Enter the list ((a b c) (d e f) (c d b a)): ";
    list k = read_list();
    list l = firsts(k);
    std::cout << "The firsts are: " << std::endl;
    write_list(l);

    std::cout << "-----Testing flat-----" << std::endl;
    std::cout << "Enter the list (a (b) (c d)): " << std::endl;
    list m = read_list();
    list n = flat(m);
    std::cout << "The flattened list is: " << std::endl;
    write_list(n);

    std::cout << "-----Testing two_the_same-----" << std::endl;
    std::cout << "Enter the list ( ( a b ) ( c d e ) ( f ( g ) ) ): ";
    list o = read_list();
    std::cout << "Enter the list ( ( c d ) l m n): ";
    list q = read_list();
    if (two_the_same(o, q)) { std::cout << "At least one matching atom";};
    if (!two_the_same(o, q)) { std::cout << "No matching atoms";};

    std::cout << "-----Testing equal-----" << std::endl;
    list r = read_list();
    list s = read_list();
*/
    std::cout << "-----Testing total_reverse-----" << std::endl;
    std::cout << "Enter the list ( ( ( j k ) ( l ) ) ( m ( n o ) ( p ) ) ( ( q r ) ( s ) ) ( t ( jj kk ) ( ll ( nn ( oo ( zx ) ) ) ) ) ): ";
    list t = read_list();
    list u = total_reverse(t);
    std::cout << "The reverse of that list is: ";
    write_list(u);

    return 0;
}
