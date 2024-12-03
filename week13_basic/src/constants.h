//
//  constants.h
//  week13_basic
//
//  Created by Gang il Lee on 11/27/24.
//

#ifndef constants_h
#define constants_h

const float G = 1.0f; // const가 없으면 linker 에러
// const 변수는 기본적으로 internal linkage를 가지므로, 각 파일에서 독립적으로 정의되어 충돌을 방지.
// const를 제거하면 변수는 기본적으로 external linkage.
// 이 경우, 변수가 전역 심볼로 선언되어 모든 소스 파일에서 동일한 심볼을 참조하게 된다.
// 이 헤더를 참조하는 곳이 두군데 이상일 경우 ld: 1 duplicate symbols 에러 발생.

const int AGE_LIMIT = 20000;

#endif /* constants_h */
