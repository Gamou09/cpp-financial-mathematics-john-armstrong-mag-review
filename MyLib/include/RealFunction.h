//
//  Header.h
//  MyLIbStaticTrue
//
//  Created by Martial Aguessi on 12/09/2026.
//

#ifndef Header_h
#define Header_h

class RealFunction {
    
public:
    /* A vitual destructor */
    virtual ~RealFunction() {} ;
    
    /* This method is abstract there is no definition*/
    virtual double evaluate (double x) const = 0 ;
    
};


#endif /* Header_h */
