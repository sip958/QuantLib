/*
 * Copyright (C) 2001
 * Ferdinando Ametrano, Luigi Ballabio, Adolfo Benin, Marco Marchioro
 * 
 * This file is part of QuantLib.
 * QuantLib is a C++ open source library for financial quantitative
 * analysts and developers --- http://quantlib.sourceforge.net/
 *
 * QuantLib is free software and you are allowed to use, copy, modify, merge,
 * publish, distribute, and/or sell copies of it under the conditions stated 
 * in the QuantLib License.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You should have received a copy of the license along with this file;
 * if not, contact ferdinando@ametrano.net
 *
 * QuantLib license is also available at 
 *      http://quantlib.sourceforge.net/LICENSE.TXT
*/

/*! \file dividendoption.h
    \brief base class for option with dividends
    
    $Source$
    $Log$
    Revision 1.2  2001/03/21 09:56:47  marmar
    virtual method added

    Revision 1.1  2001/03/20 15:15:55  marmar
    DividendOption and DividendShoutOption are examples of
     MultiPeriodOption's
    
*/

#ifndef shaft_dividend_option_pricer_h
#define shaft_dividend_option_pricer_h

#include "qldefines.h"
#include "multiperiodoption.h"

namespace QuantLib {

    namespace Pricers {

        class DividendOption : public MultiPeriodOption {
          public:
            // constructor
            DividendOption(Type type, double underlying, 
                double strike, Rate dividendYield, Rate riskFreeRate, 
                Time residualTime, double volatility, 
                const std::vector<double>& dividends = std::vector<double>(), 
                const std::vector<Time>& exdivdates = std::vector<Time>(), 
                int timeSteps = 100, int gridPoints = 100);
            private:
            std::vector<double> dividends_;
            
            void executeIntermediateStep(int step) const;
            
            void movePricesBeforeExDiv(double Div, const Array& newGrid, 
                Array& prices, const Array& oldGrid) const;

            double addElements(const std::vector<double>& A) const{
                return std::accumulate(A.begin(), A.end(), 0.0);   
            }
        };

    }

}

#endif
