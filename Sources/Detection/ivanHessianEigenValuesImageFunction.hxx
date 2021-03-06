/*=========================================================================

Image-based Vascular Analysis Toolkit (IVAN)

Copyright (c) 2012, Iván Macía Oliver
Vicomtech Foundation, San Sebastián - Donostia (Spain)
University of the Basque Country, San Sebastián - Donostia (Spain)

All rights reserved

See LICENSE file for license details

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
IMPLIED WARRANTIES SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR 
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
SUCH DAMAGE.

==========================================================================*/
// File: ivanHessianEigenValuesImageFunction.hxx
// Author: Iv�n Mac�a (imacia@vicomtech.org)
// Description: 
// Date: 2010/08/16

#ifndef __ivanHessianEigenValuesImageFunction_hxx
#define __ivanHessianEigenValuesImageFunction_hxx

#include "ivanHessianEigenValuesImageFunction.h"


namespace ivan
{
  
template <class TInputImage, class TCoordRep>
HessianEigenValuesImageFunction<TInputImage,TCoordRep>
::HessianEigenValuesImageFunction()
{

}


template <class TInputImage, class TCoordRep>
HessianEigenValuesImageFunction<TInputImage,TCoordRep>
::~HessianEigenValuesImageFunction()
{
  
}


/** Print self method */
template <class TInputImage, class TCoordRep>
void
HessianEigenValuesImageFunction<TInputImage,TCoordRep>
::PrintSelf( std::ostream& os, itk::Indent indent ) const
{
  Superclass::PrintSelf( os, indent );

}


template <class TInputImage, class TCoordRep>
typename HessianEigenValuesImageFunction<TInputImage,TCoordRep>::OutputType
HessianEigenValuesImageFunction<TInputImage,TCoordRep>
::EvaluateVesselness( const HessianTensorType & hessian ) const
{
  typedef typename HessianTensorType::EigenValuesArrayType   EigenValuesArrayType;
  EigenValuesArrayType   eigenValues;
  
  // Calculate eigenvalues of Hessian matrix at the current location
  hessian.ComputeEigenValues( eigenValues );
  
  return eigenValues;
}

} // end namespace ivan

#endif
