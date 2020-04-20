//
// Created by Cale Wolf on 4/19/20.
//

#include "scalefinder/scale.h"

namespace scalefinder {

Scale::Scale(Pitch tonic, ScaleType type) {
  name_ = GetScaleName();
}

}  // namespace scalefinder