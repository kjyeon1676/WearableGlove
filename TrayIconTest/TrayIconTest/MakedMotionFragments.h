#pragma once
#include "MotionFragment.h"

struct ThumbBend{
	const int min = -987654321;
	const int max = 987654321;
	const int semiLevel = 18;
	const int halfLevel = 16;
	const int fullLevel = 13;
	const ONE stright = ONE(semiLevel, max);
	const ONE semi = ONE(min, semiLevel);
	const ONE half = ONE(min, halfLevel);
	const ONE full = ONE(min, fullLevel);
};
struct IndexBend{
	const int min = -987654321;
	const int max = 987654321;
	const int semiLevel = 17;
	const int halfLevel = 15;
	const int fullLevel = 13;
	const ONE stright = ONE(semiLevel, max);
	const ONE semi = ONE(min, semiLevel);
	const ONE half = ONE(min, halfLevel);
	const ONE full = ONE(min, fullLevel);
};
struct MiddleBend{
	const int min = -987654321;
	const int max = 987654321;
	const int semiLevel = 18;
	const int halfLevel = 17;
	const int fullLevel = 16;
	const ONE stright = ONE(semiLevel, max);
	const ONE semi = ONE(min, semiLevel);
	const ONE half = ONE(min, halfLevel);
	const ONE full = ONE(min, fullLevel);
};
struct RingBend{
	const int min = -987654321;
	const int max = 987654321;
	const int semiLevel = 20;
	const int halfLevel = 18;
	const int fullLevel = 17;
	const ONE stright = ONE(semiLevel, max);
	const ONE semi = ONE(min, semiLevel);
	const ONE half = ONE(min, halfLevel);
	const ONE full = ONE(min, fullLevel);
};
struct LittleBend{
	const int min = -987654321;
	const int max = 987654321;
	const int semiLevel = 19;
	const int halfLevel = 17;
	const int fullLevel = 13;
	const ONE stright = ONE(semiLevel, max);
	const ONE semi = ONE(min, semiLevel);
	const ONE half = ONE(min, halfLevel);
	const ONE full = ONE(min, fullLevel);
};

struct MakedMotionFragments{
	const int min = -987654321;
	const int max = 987654321;
	const THREE infiThree = THREE(min, max, min, max, min, max);
	const ONE infiOne = ONE(min, max);
	const ONE bendOne = ONE(min, 17);
	const ONE straightOne = ONE(18, max);
	const ONE pushBtn = ONE(3, max);
	const ONE releaseBtn = ONE(min, 2);

	ThumbBend  thumb;
	IndexBend index;
	MiddleBend middle;
	RingBend  ring;
	LittleBend little;


	//새로 개편 되었습니다.
	//주먹을 꽉 쥐었을때 ( 기본적 on, Off converting )
	MotionFragment *punchHand = new MotionFragment(infiThree,
		infiThree,
		infiThree, bendOne, bendOne, bendOne, bendOne, bendOne, infiOne, infiOne);

	// 쭉핀 손입니다.
	MotionFragment *strightHand = new MotionFragment(infiThree,
		infiThree,
		infiThree, straightOne, straightOne, straightOne, straightOne, straightOne, infiOne, infiOne);
	//손바닥의 모양은 크게 3가지가 있습니다 노말 모드, 옆으로 사이드 모드 , 그다음 손바닥을 거꾸로 하는 인벌스 모드
	MotionFragment * normalMode = new MotionFragment(infiThree,
		THREE(min, max, min, max, 9, max),
		infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);
	MotionFragment * sideMode = new MotionFragment(infiThree,
		THREE(min, max, min, max, 4, 8),
		infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);
	MotionFragment * inverseMode = new MotionFragment(infiThree,
		THREE(min, max, min, max, min, 3),
		infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);

	//손모드는 다음 3가지 모션에서 파생되어 진행 됩니다.

	//압력센서를 이용한 모션입니다.
	//압력모션은 주의해야할 점이 있습니다. 바로 구부림 센서와 같이 인식될 확률이 있다는 것입니다.
	//그러므로 모션을 생각하여 주의깊게 사용하면 되겠습니다.
	MotionFragment *pressIndex = new MotionFragment(infiThree,
		infiThree,
		infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, pushBtn, releaseBtn);
	MotionFragment *pressMiddle = new MotionFragment(infiThree,
		infiThree,
		infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, releaseBtn, pushBtn);
	MotionFragment *pressIndexMiddle = new MotionFragment(infiThree,
		infiThree,
		infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, pushBtn, pushBtn);


	//손모드로 부터 좀 더 상세한 이벤트를 설정 할 수 있습니다.
	//모션을 너무 다양하게 만들 수 있어서 너무나도 복잡한 관계로 어느정도 개발 단계에서 제한을 하는 것으로 합니다.
	//모션은 각 손가락마다 깊이만큼의 모션을 정할 수 있습니다.
	//하지만 깊고 얇고 차이로 이벤트를 다르게 지정할려다 보니 인식시 너무 복잡한 관계로
	//깊고 얇게 둘중 하나만 선택하도록 제한합니다. 


	//얉은 클릭 모션 들 입니다.
	MotionFragment *clickThumbIndex = new MotionFragment(infiThree,
		infiThree,
		infiThree, thumb.semi, index.stright, middle.stright, ring.stright, little.stright, releaseBtn, releaseBtn);
	MotionFragment *clickIndex = new MotionFragment(infiThree,
		infiThree,
		infiThree, thumb.stright, index.semi, middle.stright, ring.stright, little.stright, releaseBtn, releaseBtn);
	MotionFragment *clickIndexMiddle = new MotionFragment(infiThree,
		infiThree,
		infiThree, thumb.stright, index.semi, middle.semi, ring.stright, little.stright, releaseBtn, releaseBtn);
	MotionFragment *clickMiddle = new MotionFragment(infiThree,
		infiThree,
		infiThree, thumb.stright, index.stright, middle.semi, ring.stright, little.stright, releaseBtn, releaseBtn);
	MotionFragment *clickIndexMiddleRing = new MotionFragment(infiThree,
		infiThree,
		infiThree, thumb.stright, index.semi, middle.semi, ring.semi, little.stright, releaseBtn, releaseBtn);
	MotionFragment *clickIndexMiddleRingLittle = new MotionFragment(infiThree,
		infiThree,
		infiThree, thumb.stright, index.semi, middle.semi, ring.semi, little.semi, releaseBtn, releaseBtn);

	MotionFragment *clickMiddleRing = new MotionFragment(infiThree,
		infiThree,
		infiThree, thumb.stright, index.stright, middle.semi, ring.semi, little.stright, releaseBtn, releaseBtn);

	MotionFragment *clickRing = new MotionFragment(infiThree,
		infiThree,
		infiThree, thumb.stright, index.stright, middle.stright, ring.semi, little.stright, releaseBtn, releaseBtn);

	//깊은 클릭 모션 틀입니다.






	////MotionFragment는 mag, acc, gyro, 다섯손가락 구부림, 두손가락 압력으로 이루어져 있습니다. 
	////acc는 중력 센서로서 THREE(7,14,7,14,min,max)인 상태는 손바닥이 평범하게 
	////위치 있을 시 모드입니다.
	//MotionFragment * normalMode = new MotionFragment(infiThree,
	//	THREE(min, max, min, max, 9, max),
	//	infiThree,infiOne, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);
	////MotionFragment *palmInFrontOf = new MotionFragment(infiThree,
	////	THREE(7, 14, 12, max, min, 8),
	////	infiThree, thumb.stright, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);;
	//////THREE(6,6,min,max,min,max)는 손바닥을 왼쪽으로 향하였을때 중력입니다.
	////MotionFragment *palmLeftSideway = new MotionFragment(infiThree,
	////	THREE(6, 6, min, 12, min, max),
	////	infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);

	//MotionFragment * sideMode = new MotionFragment(infiThree,
	//	THREE(min, max, min, max, 4, 8),
	//	infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);
	//MotionFragment * inverseMode = new MotionFragment(infiThree,
	//	THREE(min, max, min, max, min, 3),
	//	infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);

	//MotionFragment * strightHand = new MotionFragment(infiThree,
	//	THREE(min, max, min, max, 9, max),
	//	infiThree, thumb.stright, index.stright, middle.stright, ring.stright, little.stright, infiOne, infiOne);


	////밴드는 중간정도 구부렸을때
	//MotionFragment *bendThumb = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.half, index.stright, middle.stright, ring.stright, little.stright, infiOne, infiOne);
	//MotionFragment *bendIndex = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.stright, index.half, middle.stright, ring.stright, little.stright, infiOne, infiOne);
	//MotionFragment *bendIndexMiddle = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.stright, index.half, middle.half, ring.stright, little.stright, infiOne, infiOne);
	//MotionFragment *bendMiddle = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.stright, index.stright, middle.half, ring.stright, little.stright, infiOne, infiOne);
	//MotionFragment *bendThumbIndex = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.half, index.half, middle.stright, ring.stright, little.stright, infiOne, infiOne);
	//MotionFragment *bendThumbMiddle = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.half, index.stright, middle.half, ring.stright, little.stright, infiOne, infiOne);
	//MotionFragment *bendThumbRing = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.half, index.stright, middle.stright, ring.half, little.stright, infiOne, infiOne);

	////스트라이트는 혼자만 피고 나머지 다 접었을때
	//MotionFragment *strightIndex = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.half, index.stright, middle.half, ring.half, little.half, infiOne, infiOne);

	//MotionFragment *strightMiddle = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.half, index.half, middle.stright, ring.half, little.half, infiOne, infiOne);

	//MotionFragment *strightIndexMiddle = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.half, index.stright, middle.stright, ring.half, little.half, infiOne, infiOne);

	//MotionFragment *okSign = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.half, index.half, middle.stright, ring.stright, little.stright, infiOne, infiOne);

	//MotionFragment * strightThumbIndexMiddle = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, straightOne, straightOne, straightOne, bendOne, bendOne, infiOne, infiOne);

	/////주먹을 꽉 쥐었을때
	//MotionFragment *punchHand = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, bendOne, bendOne, bendOne, bendOne, bendOne, infiOne, infiOne);
	//


	////클릭은 가볍게 클릭할때
	//MotionFragment *clickThumbIndex = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.semi, index.semi, middle.stright, ring.stright, little.stright, infiOne, infiOne);
	//MotionFragment *clickIndex = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.stright, index.semi, middle.stright, ring.stright, little.stright, infiOne, infiOne);
	//MotionFragment *clickIndexMiddle = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.stright, index.semi, middle.semi, ring.stright, little.stright, infiOne, infiOne);
	//MotionFragment *clickMiddle = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.stright, index.stright, middle.semi, ring.stright, little.stright, infiOne, infiOne);
	//MotionFragment *clickIndexMiddleRing = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.stright, index.semi, middle.semi, ring.semi, little.stright, infiOne, infiOne);
	//MotionFragment *clickIndexMiddleRingLittle = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.stright, index.semi, middle.semi, ring.semi, little.semi, infiOne, infiOne);


	////엄지를 최대로 구브렸을때
	//MotionFragment *fullBendThumb = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.full, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);
	//MotionFragment *releaseThumb = new MotionFragment(infiThree, infiThree, infiThree,
	//	ONE(thumb.semiLevel, max), infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);
	////사이드 모션
	//MotionFragment * sideModeOkSign = new MotionFragment(infiThree,
	//	THREE(min, max, min, max, 4, 8),
	//	infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, pushBtn, releaseBtn);

	//MotionFragment * anyWayOkSign = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, pushBtn, releaseBtn);

	//MotionFragment * fullThumbBendIndex = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.full, index.half, infiOne, infiOne, infiOne, infiOne, infiOne);

	//MotionFragment * fullThumbReleaseIndex = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.full, index.stright, infiOne, infiOne, infiOne, infiOne, infiOne);
};