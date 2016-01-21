/**
 * Project \
 */


#ifndef _DUALFEEDBACK_H
#define _DUALFEEDBACK_H

#include "SearchFeedback.h"


class DualFeedback: public SearchFeedback {
public: 
    
    /**
     * @param feedback
     */
    void setFeedback(int feedback);
};

#endif //_DUALFEEDBACK_H