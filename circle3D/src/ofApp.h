#include "ofMain.h"

class Circle3D {
public:
    ofVec3f position;
    ofVec3f velocity;
    float radius;
    ofColor color;

    Circle3D(ofVec3f pos, ofVec3f vel, float r, ofColor c)
        : position(pos), velocity(vel), radius(r), color(c) {}

    void update(float boundaryX, float boundaryY, float boundaryZ) {
        position += velocity;

        if (position.x - radius < -boundaryX || position.x + radius > boundaryX) {
            velocity.x *= -1;
        }
        if (position.y - radius < -boundaryY || position.y + radius > boundaryY) {
            velocity.y *= -1;
        }
        if (position.z - radius < -boundaryZ || position.z + radius > boundaryZ) {
            velocity.z *= -1;
        }
    }

    void draw() {
        ofSetColor(color);
        ofDrawSphere(position, radius);
    }
};

class ofApp : public ofBaseApp {
public:
    ofEasyCam cam;
    vector<Circle3D> circles;
    float boundaryX = 400, boundaryY = 300, boundaryZ = 200;

    ofLight pointLight;   // 점 조명
    ofLight spotLight;    // 스포트라이트
    ofMaterial material;  // 구체에 반사 효과 추가

    void setup() {
        ofBackground(0);
        ofEnableDepthTest(); // 깊이 테스트 활성화
        ofEnableLighting();  // 조명 활성화

        // 점 조명 설정
        pointLight.setPointLight();
        pointLight.setPosition(0, 0, 500); // 화면 앞쪽에 배치
        pointLight.setDiffuseColor(ofColor(255, 200, 200)); // 확산광 색상
        pointLight.setSpecularColor(ofColor(255, 255, 255)); // 반사광 색상

        // 스포트라이트 설정
        spotLight.setSpotlight();
        spotLight.setPosition(300, 300, 300);
        spotLight.setDiffuseColor(ofColor(200, 255, 200));
        spotLight.setSpecularColor(ofColor(255, 255, 255));
        spotLight.setSpotlightCutOff(30); // 스포트라이트 각도
        spotLight.setSpotConcentration(2); // 빛 집중도

        // 물질(Material) 설정
        material.setShininess(64); // 표면의 반짝임 정도
        material.setSpecularColor(ofColor(255, 255, 255));

        // 동그라미 생성
        for (int i = 0; i < 50; i++) {
            ofVec3f pos(ofRandom(-boundaryX, boundaryX),
                        ofRandom(-boundaryY, boundaryY),
                        ofRandom(-boundaryZ, boundaryZ));
            ofVec3f vel(ofRandom(-2, 2), ofRandom(-2, 2), ofRandom(-2, 2));
            float radius = ofRandom(10, 20);
            ofColor color = ofColor::fromHsb(ofRandom(255), 200, 255);
            circles.emplace_back(pos, vel, radius, color);
        }
    }

    void update() {
        for (auto &circle : circles) {
            circle.update(boundaryX, boundaryY, boundaryZ);
        }
    }

    void draw() {
        cam.begin();

        // 조명 활성화
        //pointLight.enable();
        spotLight.enable();
        material.begin();

        // 3D 공간 경계 박스 그리기
        ofNoFill();
        ofSetColor(255);
        ofDrawBox(0, 0, 0, boundaryX * 2, boundaryY * 2, boundaryZ * 2);

        // 동그라미 그리기
        for (auto &circle : circles) {
            circle.draw();
        }

        material.end();
        pointLight.disable();
        spotLight.disable();

        cam.end();
    }
};
