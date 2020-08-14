/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/core/framework/op.h"
#include "tensorflow/core/framework/shape_inference.h"

using namespace tensorflow;

REGISTER_OP("LshMatmul")
    .Input("a: T")
    .Input("b: T")
    .Input("l: Ref(T)")
    .Input("r: Ref(T)")
    .Input("i: Ref(T)")
    .Input("w: Ref(T)")
    .Output("product: T")
    .Attr("transpose_a: bool = false")
    .Attr("transpose_b: bool = false")
    .Attr(
        "T: {bfloat16, half, float, double, int32, int64, complex64, "
        "complex128}")
    .SetShapeFn(shape_inference::MatMulShape);
