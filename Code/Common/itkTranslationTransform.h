/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSFile: itkTranslationTransform.h.v $
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

Copyright (c) 2001 Insight Consortium
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * The name of the Insight Consortium, nor the names of any consortium members,
   nor of any contributors, may be used to endorse or promote products derived
   from this software without specific prior written permission.

  * Modified source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/

#ifndef __itkTranslationTransform_h
#define __itkTranslationTransform_h

#include <iostream>
#include "itkTransform.h"
#include "itkExceptionObject.h"



namespace itk
{

/**
 *
 * Translation transformation of a vector space (e.g. space coordinates)
 *
 * The same functionality could be obtained by using the Affine tranform,
 * but with a large difference in performace
 *
 **/

template <
    class TScalarType,          // Data type for scalars (float or double)
    unsigned int NDimensions >  // Number of dimensions
class TranslationTransform : public Transform< TScalarType, NDimensions >
{
public:

    /**
     * Standard Self Typedef
     */
    typedef TranslationTransform Self;

    /// Standard scalar type for this class
    typedef TScalarType ScalarType;

    /// Dimension of the domain space
    enum { SpaceDimension     = NDimensions };

    /// Standard vector type for this class
    typedef Vector<TScalarType, SpaceDimension> VectorType;

    /// Standard covariant vector type for this class
    typedef CovariantVector<TScalarType, SpaceDimension> CovariantVectorType;

    /// Standard vnl_vector type for this class
    typedef vnl_vector_fixed<TScalarType, SpaceDimension> VnlVectorType;

    /// Standard coordinate point type for this class
    typedef Point<TScalarType, SpaceDimension> PointType;


    /**
     * Construct an TranslationTransform object
     *
     **/
    TranslationTransform(const VectorType &offset);
    TranslationTransform();

    /**
     * Copy an TranslationTransform object
     *
     * This method creates a new TranslationTransform object and
     * initializes it to be a copy of an existing TranslationTransform.
     **/
    TranslationTransform(const Self & other);

    /**
     * Destroy an TranslationTransform object
     **/
    ~TranslationTransform();

    /**
     * Get offset of an TranslationTransform
     *
     * This method returns the value of the offset of the
     * TranslationTransform.
     **/
    const VectorType & GetOffset() const
        { return m_Offset; }

    /**
     * Assignment operator
     **/
    const Self & operator=( const Self & );

    /**
     * Set offset of an Translation Transform
     *
     * This method sets the offset of an TranslationTransform to a
     * value specified by the user.
     **/
    void SetOffset(const VectorType &offset)
        { m_Offset = offset; return; }

    /**
     * Compose with another TranslationTransform
     *
     **/
    void Compose(const Self &other, bool pre=0);

    /**
     * Compose affine transformation with a translation
     *
     * This method modifies self to include a translation of the
     * origin.  The translation is precomposed with self if pre is
     * true, and postcomposed otherwise.
     **/
    void Translate(const VectorType &offset, bool pre=0);

    /**
     * Transform by an affine transformation
     *
     * This method applies the affine transform given by self to a
     * given point or vector, returning the transformed point or
     * vector.
     **/
    PointType           Transform(const PointType  &point ) const;
    VectorType          Transform(const VectorType &vector) const;
    VnlVectorType       Transform(const VnlVectorType &vector) const;

    CovariantVectorType Transform(
                                   const CovariantVectorType &vector) const;

    /**
     * Back transform by an affine transformation
     *
     * This method finds the point or vector that maps to a given
     * point or vector under the affine transformation defined by
     * self.  If no such point exists, an exception is thrown.
     **/
    inline PointType           BackTransform(const PointType  &point ) const;
    inline VectorType          BackTransform(const VectorType &vector) const;
    inline VnlVectorType       BackTransform(const VnlVectorType &vector) const;

    inline CovariantVectorType BackTransform(
                                       const CovariantVectorType &vector) const;
    /**
     * Print contents of an TranslationTransform
     **/
    std::ostream & PrintSelf(std::ostream &s) const;

    /**
     * Find inverse of an affine transformation
     *
     * This method creates and returns a new TranslationTransform object
     * which is the inverse of self.  If self is not invertible,
     * an exception is thrown.
     **/
    TranslationTransform Inverse();


private:
    VectorType   m_Offset;       // Offset of the transformation


}; //class TranslationTransform


/**
 * Print the offset of a TranslationTransform
 * This method prints the offset of the
 * TranslationTransform as n vector.
 **/
                                                              
 template<class ScalarType, unsigned int NDimensions>
 inline
 std::ostream &
 operator<< (std::ostream &s, TranslationTransform<ScalarType, NDimensions> &affine)
 {
     return affine.PrintSelf(s);
 }


}  // namespace itk


#ifndef ITK_MANUAL_INSTANTIATION
#include "itkTranslationTransform.txx"
#endif

#endif /* __itkTranslationTransform_h */
