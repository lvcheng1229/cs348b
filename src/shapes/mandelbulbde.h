
/*
    pbrt source code is Copyright(c) 1998-2016
                        Matt Pharr, Greg Humphreys, and Wenzel Jakob.

    This file is part of pbrt.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are
    met:

    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
    IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
    TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
    HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
    SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
    DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
    THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#if defined(_MSC_VER)
#define NOMINMAX
#pragma once
#endif

#ifndef PBRT_SHAPES_MANDELBULBDE_H
#define PBRT_SHAPES_MANDELBULBDE_H

// shapes/sphere.h*
#include "shape.h"
#include "distanceestimator.h"

namespace pbrt {

// Sphere Declarations
class MandelbulbDE : public DistanceEstimator {
  public:
    // Sphere Public Methods
    MandelbulbDE(const Transform *ObjectToWorld, const Transform *WorldToObject,
           bool reverseOrientation,  int mandelbulbPower, int fractalIters, int maxiters, float hitEpsilon, int rayEpsilonMultiplier, float normalEpsilon)
        : DistanceEstimator(ObjectToWorld, WorldToObject, reverseOrientation,maxiters, hitEpsilon, rayEpsilonMultiplier, normalEpsilon),
          mandelbulbPower(mandelbulbPower),
          fractalIters(fractalIters){}

    Bounds3f ObjectBound() const;
    Float Area() const;
    Interaction Sample(const Point2f &u, Float *pdf) const;
    Float Evaluate(const Point3f& p) const;


  private:
    int mandelbulbPower; 
    int fractalIters;
    // Sphere Private Data
    // important for generic Distance Estimator
    // int maxiters; // Number of steps along the ray until we give up (default 1000)
    // float hitEpsilon; // how close to the surface we must be before we say we "hit" it
    // float rayEpsilonMultiplier; // how much we multiply hitEpsilon by to get pError
    // float normalEpsilon; // The epsilon we send to CalculateNormal()


};

std::shared_ptr<Shape> CreateMandelbulbDEShape(const Transform *o2w,
                                         const Transform *w2o,
                                         bool reverseOrientation,
                                         const ParamSet &params);

}  // namespace pbrt

#endif  // PBRT_SHAPES_SPHERE_H
