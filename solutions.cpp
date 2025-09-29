#include "reclists.hpp"
#include "solutions.hpp"

#include <utility>

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp.
//


int numNodesAtTheTopLevel(list p) {
    // p is one of
    //    a null list
    //    an atom
    //    a recursive list

    // The function returns the number of nodes at the top-level
    // of p.

    if( is_null(p) )
        return 0;
    if( is_atom(p) )
        return 1;
    return 1 + numNodesAtTheTopLevel(cdr(p));
}
list append(list p, list q) {
    if (is_null(p))
        return q;
    return cons(car(p), append(cdr(p), q));
}

/**
 * takes a list and returns true if the list consists entirely of atom.
 * @param p
 * @return true or false
 */
bool is_lat(list p) {

    if( is_null(p) ) {
        return true;
    }
    if( !is_atom(car(p)) ) { //checks if current element is an atom
        return false;
    }
    return is_lat(cdr(p)); //moves to next element
}

/**
 * takes an atom p and a list q and returns true if p appears in q.
 * @param p
 * @param q
 * @return true or false
 */
bool member(list p, list q) {
    if (is_null(q)) { //if q is null then p is not a member of q
        return false;
    }
    if (is_atom(car(q)) && eq(p, car(q)) ) { //checks if atom is equal to atom in q
        return true;
    }
    return member(p, cdr(q)); //iterates through list q
}



/**
 * takes a non-empty list and returns its last element.
 * @param p
 * @return last element of list
 */
list last(list p) {
    if (is_null(cdr(p))) { //checks if next element is null and if so returns element
        return car(p);
    }
    return last(cdr(p)); //iterates through list p
}

/**
 * takes two lists of atoms and returns a list pf pairs where each pair contains corresponding atoms
 * @param p
 * @param q
 * @return a list of pairs
 */
list list_pair (list p, list q) {
    if (is_null(p) && is_null(q)) { //checks if done iterating through lists
        return null();
    }
    return cons(cons(car(p), cons(car(q),null())), list_pair(cdr(p), cdr(q))); //cons pairs together and moves to next elments
}

/**
 * takes list as input and returns a list of the first atoms in sublists
 * @param p
 * @return
 */

list firsts(list p) {
    if (is_null(p)) {
        return null();
    }
    return cons(car(car(p)), firsts(cdr(p))); //cons the first element of subslists and iterates through list p
}

/**
 * takes a list and returns a list with all nested parentheses are removed
 * @param p
 * @return list with no parentheses
 */
list flat (list p) {
    if (is_null(p)) { //checks if list is empty
        return p;
    }
    if (is_atom (car(p))) { //checks if current element is an atom and cons it
        return cons(car(p), flat(cdr(p)));
    }
    return append (flat(car (p)), flat(cdr(p))); //checks for nested lists and iterates through list p
}

/**
 * takes two lists and returns true if p and q contain at least one atom in common
 * @param p 
 * @param q 
 * @return true or false
 */
bool two_the_same(list p, list q) {
    if (is_null(p)) {
        return false;
    }
    list a = flat(p); //flatten list p and list q to iterate through lists quickly
    list b = flat(q);
    if (member(car(a), b)){ //use member function to iterate through list q and see if current element is in q
        return true;
    }
    return two_the_same(cdr(a), b); //iterates through list p
}

/**
 * takes two lists and determines if they are identical
 * @param p
 * @param q
 * @return true or false
 */
bool equal(list p, list q) {
    if (is_null(p) && is_null(q)) { //if we get to end of both lists without returning false then return true
        return true;
    }
    if (is_null(p) || is_null(q)) { //checks if lists are equal in size if not then returns false
        return false;
    }
    if (is_atom(p) && is_atom(q)) { //checks if atoms are equal to one another
        return eq(p, q);
    }
    return equal(car(p), car(q)) && equal(cdr(p), cdr(q)); //iterates through lists
}

/**
 * takes a list and returns its mirror image
 * @param p
 * @return reversed list
 */
list total_reverse(list p) {
    if (is_null(p)) { //checks if list is empty
        return null();
    }
    if (!is_atom(car(p))) { //checks for nested lists and cons them
        return append(total_reverse(cdr(p)), cons(total_reverse(car(p)), null()));
    }
return append(total_reverse(cdr(p)), cons(car(p), null())); //iterates through list p and cons elements in reverse
}

/**
 * takes a list and returns only parentheses of list
 * @param p 
 * @return list of only parentheses
 */
list shape(list p) {
    if (is_null(p)) { //checks if list is empty
        return null();
    }
    if (is_atom(p)) { //checks if there's an atom if so then
        return null();
    }
    return cons(shape(car(p)), shape(cdr(p))); //iterates through list p and cons all parentheses
}

/**
 * takes two lists of distinct atoms and returns a list of atoms that appear in both
 * @param p
 * @param q
 * @return list of common atoms
 */
list intersection(list p, list q) {
    if (is_null(p)) { //checks if p is empty
        return null();
    }
    if (member(car(p), q)) { //uses member to iterate through q and check if p is in q
        return cons(car(p), intersection(cdr(p), q)); //if so it's added to the list
    }
    return intersection(cdr(p), q); //iterates through list p
}

/**
 * takes two lists of distinct and returns a list of union without repetition
 * @param p
 * @param q
 * @return list of atoms in common without repetition
 */
list list_union(list p, list q) {
    if (is_null(p)) { //checks if p is empty
        return null();
    }
    if (member(car(p), q) && !member(car(p), intersection(cdr(p), q))) { //checks if p is in q and if p is not in q
        return cons(car(p), list_union(cdr(p),q)); //if so it adds p to new list
    }
    return list_union(cdr(p), q); //iterates through list p
}

/**
 * takes a list of atoms and returns list with every occurence of old atom replaced with new
 * @param old
 * @param new_list
 * @param p
 * @return list p with old atoms replaced by new atoms
 */
list substitute(list old, list new_list, list p) {
    if (is_null(p)) {
        return null();
    }
    if (eq(car(p), old)) { //checks if old atom is equal to atom in p if so it's substituted
        return cons(new_list, substitute(old, new_list, cdr(p)));
    }
    return cons(car(p), substitute(old, new_list, cdr(p))); //iterates through list p and cons elements that aren't old atom
}

/**
 * takes a list of atoms and removes one specific atom from entire list
 * @param p
 * @param q
 * @return list without the one atom
 */
list remove (list p, list q) {
    if (is_null(p)) { //checks if p is empty
        return null();
    }
    if (eq(car(p), q)) { //if atom is equal to one we need to remove then skip
        return remove(cdr(p), q);
    }
    return cons(car(p), remove(cdr(p), q)); //iterates through p and cons every atom that is not atom q
}

/**
 * takes two lists and returns true if every atom in p appears in q
 * @param p
 * @param q
 * @return true or false
 */
bool subset(list p, list q) {
    if (is_null(p)) {
        return true;
    }
    list a = flat (p); //flatten lists to iterate easier
    list b = flat (q);
    if (!member(car(a), b)) { //use member to iterate through list q and check if p is in q
        return false;
    }
    return subset(cdr(p), q); //iterates through p
}