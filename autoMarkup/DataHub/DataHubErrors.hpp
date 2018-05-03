#ifndef DataHubErrors_hpp
#define DataHubErrors_hpp

#include <exception>

class EmptyTokenError: public std::exception{
    virtual const char* what() const throw() { return "Array(vector) of tokens is empty";}
} EmptyTokenException;

#endif /* DataHubErrors_hpp */
