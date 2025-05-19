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

    ofLight pointLight;   // �� ����
    ofLight spotLight;    // ����Ʈ����Ʈ
    ofMaterial material;  // ��ü�� �ݻ� ȿ�� �߰�

    void setup() {
        ofBackground(0);
        ofEnableDepthTest(); // ���� �׽�Ʈ Ȱ��ȭ
        ofEnableLighting();  // ���� Ȱ��ȭ

        // �� ���� ����
        pointLight.setPointLight();
        pointLight.setPosition(0, 0, 500); // ȭ�� ���ʿ� ��ġ
        pointLight.setDiffuseColor(ofColor(255, 200, 200)); // Ȯ�걤 ����
        pointLight.setSpecularColor(ofColor(255, 255, 255)); // �ݻ籤 ����

        // ����Ʈ����Ʈ ����
        spotLight.setSpotlight();
        spotLight.setPosition(300, 300, 300);
        spotLight.setDiffuseColor(ofColor(200, 255, 200));
        spotLight.setSpecularColor(ofColor(255, 255, 255));
        spotLight.setSpotlightCutOff(30); // ����Ʈ����Ʈ ����
        spotLight.setSpotConcentration(2); // �� ���ߵ�

        // ����(Material) ����
        material.setShininess(64); // ǥ���� ��¦�� ����
        material.setSpecularColor(ofColor(255, 255, 255));

        // ���׶�� ����
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

        // ���� Ȱ��ȭ
        //pointLight.enable();
        spotLight.enable();
        material.begin();

        // 3D ���� ��� �ڽ� �׸���
        ofNoFill();
        ofSetColor(255);
        ofDrawBox(0, 0, 0, boundaryX * 2, boundaryY * 2, boundaryZ * 2);

        // ���׶�� �׸���
        for (auto &circle : circles) {
            circle.draw();
        }

        material.end();
        pointLight.disable();
        spotLight.disable();

        cam.end();
    }
};
