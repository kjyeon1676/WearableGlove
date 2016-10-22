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


	//���� ���� �Ǿ����ϴ�.
	//�ָ��� �� ������� ( �⺻�� on, Off converting )
	MotionFragment *punchHand = new MotionFragment(infiThree,
		infiThree,
		infiThree, bendOne, bendOne, bendOne, bendOne, bendOne, infiOne, infiOne);

	// ���� ���Դϴ�.
	MotionFragment *strightHand = new MotionFragment(infiThree,
		infiThree,
		infiThree, straightOne, straightOne, straightOne, straightOne, straightOne, infiOne, infiOne);
	//�չٴ��� ����� ũ�� 3������ �ֽ��ϴ� �븻 ���, ������ ���̵� ��� , �״��� �չٴ��� �Ųٷ� �ϴ� �ι��� ���
	MotionFragment * normalMode = new MotionFragment(infiThree,
		THREE(min, max, min, max, 9, max),
		infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);
	MotionFragment * sideMode = new MotionFragment(infiThree,
		THREE(min, max, min, max, 4, 8),
		infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);
	MotionFragment * inverseMode = new MotionFragment(infiThree,
		THREE(min, max, min, max, min, 3),
		infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);

	//�ո��� ���� 3���� ��ǿ��� �Ļ��Ǿ� ���� �˴ϴ�.

	//�з¼����� �̿��� ����Դϴ�.
	//�з¸���� �����ؾ��� ���� �ֽ��ϴ�. �ٷ� ���θ� ������ ���� �νĵ� Ȯ���� �ִٴ� ���Դϴ�.
	//�׷��Ƿ� ����� �����Ͽ� ���Ǳ�� ����ϸ� �ǰڽ��ϴ�.
	MotionFragment *pressIndex = new MotionFragment(infiThree,
		infiThree,
		infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, pushBtn, releaseBtn);
	MotionFragment *pressMiddle = new MotionFragment(infiThree,
		infiThree,
		infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, releaseBtn, pushBtn);
	MotionFragment *pressIndexMiddle = new MotionFragment(infiThree,
		infiThree,
		infiThree, infiOne, infiOne, infiOne, infiOne, infiOne, pushBtn, pushBtn);


	//�ո��� ���� �� �� ���� �̺�Ʈ�� ���� �� �� �ֽ��ϴ�.
	//����� �ʹ� �پ��ϰ� ���� �� �־ �ʹ����� ������ ����� ������� ���� �ܰ迡�� ������ �ϴ� ������ �մϴ�.
	//����� �� �հ������� ���̸�ŭ�� ����� ���� �� �ֽ��ϴ�.
	//������ ��� ��� ���̷� �̺�Ʈ�� �ٸ��� �����ҷ��� ���� �νĽ� �ʹ� ������ �����
	//��� ��� ���� �ϳ��� �����ϵ��� �����մϴ�. 


	//���� Ŭ�� ��� �� �Դϴ�.
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

	//���� Ŭ�� ��� Ʋ�Դϴ�.






	////MotionFragment�� mag, acc, gyro, �ټ��հ��� ���θ�, �μհ��� �з����� �̷���� �ֽ��ϴ�. 
	////acc�� �߷� �����μ� THREE(7,14,7,14,min,max)�� ���´� �չٴ��� ����ϰ� 
	////��ġ ���� �� ����Դϴ�.
	//MotionFragment * normalMode = new MotionFragment(infiThree,
	//	THREE(min, max, min, max, 9, max),
	//	infiThree,infiOne, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);
	////MotionFragment *palmInFrontOf = new MotionFragment(infiThree,
	////	THREE(7, 14, 12, max, min, 8),
	////	infiThree, thumb.stright, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);;
	//////THREE(6,6,min,max,min,max)�� �չٴ��� �������� ���Ͽ����� �߷��Դϴ�.
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


	////���� �߰����� ���η�����
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

	////��Ʈ����Ʈ�� ȥ�ڸ� �ǰ� ������ �� ��������
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

	/////�ָ��� �� �������
	//MotionFragment *punchHand = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, bendOne, bendOne, bendOne, bendOne, bendOne, infiOne, infiOne);
	//


	////Ŭ���� ������ Ŭ���Ҷ�
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


	////������ �ִ�� ���������
	//MotionFragment *fullBendThumb = new MotionFragment(infiThree,
	//	infiThree,
	//	infiThree, thumb.full, infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);
	//MotionFragment *releaseThumb = new MotionFragment(infiThree, infiThree, infiThree,
	//	ONE(thumb.semiLevel, max), infiOne, infiOne, infiOne, infiOne, infiOne, infiOne);
	////���̵� ���
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