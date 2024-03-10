#include "Shape2D.h"
#include <iostream>
#include <string>

class Triangle : public Shape2D {
private:
    float base;
    float height;
public:
    Triangle(float b, float h) : base(b), height(h) { CalculateArea(); }
    void Scale(float scaleFactor) override {
        base *= scaleFactor;
        height *= scaleFactor;
        CalculateArea();
    }
    void ShowInfo() override {
        std::cout << "Я треугольник!" << std::endl;
        std::cout << "Моя площадь = " << GetArea() << std::endl;
        std::cout << "Длина моего основания = " << base << std::endl;
        std::cout << "Моя высота = " << height << std::endl;
    }
    std::string GetName() const override { return "Triangle"; }
    void CalculateArea() override {
        area = 0.5f * base * height;
    }

};
#include "Triangle.h"
#include "Circle.h"
#include "TriangularPyramid.h"
#include "Cylinder.h"
#include "Sphere.h"

void TestShapes() {
    Triangle triangle(10, 2);
    triangle.ShowInfo();

    Circle circle(5);
    circle.ShowInfo();

    TriangularPyramid pyramid(10, 2, 5);
    pyramid.ShowInfo();

    Cylinder cylinder(5, 10);
    cylinder.ShowInfo();

    Sphere sphere(5);
    sphere.ShowInfo();
}

int main() {
    TestShapes();
    return 0;
}
#pragma once
#include <iostream>

class Shape2D {
protected:
    float area;
public:
    virtual void CalculateArea() = 0;
    virtual void Scale(float scaleFactor) = 0;
    virtual void ShowInfo() = 0;
    virtual std::string GetName() const = 0;
    float GetArea() const { return area; }
};
#pragma once
#include "Shape2D.h"
#include <iostream>
#include <cmath>

class Circle : public Shape2D {
private:
    float radius;
public:
    Circle(float r) : radius(r) { CalculateArea(); }
    void Scale(float scaleFactor) override {
        radius *= scaleFactor;
        CalculateArea();
    }
    void ShowInfo() override {
        std::cout << "Я круг!" << std::endl;
        std::cout << "Моя площадь = " << GetArea() << std::endl;
        std::cout << "Мой радиус = " << radius << std::endl;
    }
    std::string GetName() const override { return "Circle"; }
    void CalculateArea() override {
        area = M_PI * radius * radius;
    }
};
#pragma once
#include <iostream>

class Shape3D {
protected:
    float volume;
public:
    virtual void CalculateVolume() = 0;
    virtual void Scale(float scaleFactor) = 0;
    virtual void ShowInfo() = 0;
    virtual std::string GetName() const = 0;
    float GetVolume() const { return volume; }
};
#pragma once
#include "Shape3D.h"
#include "Triangle.h"

class TriangularPyramid : public Shape3D {
private:
    Triangle baseTriangle;
    float height;
public:
    TriangularPyramid(float base, float height, float pyramidHeight) : baseTriangle(base, height), height(pyramidHeight) {
        CalculateVolume();
    }
    void Scale(float scaleFactor) override {
        baseTriangle.Scale(scaleFactor);
        height *= scaleFactor;
        CalculateVolume();
    }
    void ShowInfo() override {
        std::cout << "Я треугольная пирамида!" << std::endl;
        std::cout << "Мой объем = " << GetVolume() << std::endl;
        std::cout << "Высота моей пирамиды = " << height << std::endl;
        baseTriangle.ShowInfo();
    }
    std::string GetName() const override { return "TriangularPyramid"; }
    void CalculateVolume() override {
        volume = (baseTriangle.GetArea() * height) / 3.0f;
    }
};
#pragma once
#include "Shape3D.h"
#include "Circle.h"

class Cylinder : public Shape3D {
private:
    Circle baseCircle;
    float height;
public:
    Cylinder(float radius, float h) : baseCircle(radius), height(h) { CalculateVolume(); }
    void Scale(float scaleFactor) override {
        baseCircle.Scale(scaleFactor);
        height *= scaleFactor;
        CalculateVolume();
    }
    void ShowInfo() override {
        std::cout << "Я цилиндр!" << std::endl;
        std::cout << "Мой объем = " << GetVolume() << std::endl;
        std::cout << "Высота моего цилиндра = " << height << std::endl;
        baseCircle.ShowInfo();
    }
    std::string GetName() const override { return "Cylinder"; }
    void CalculateVolume() override {
        volume = baseCircle.GetArea() * height;
    }
};
#pragma once
#include "Shape3D.h"
#include <cmath>

class Sphere : public Shape3D {
private:
    float radius;
public:
    Sphere(float r) : radius(r) { CalculateVolume(); }
    void Scale(float scaleFactor) override {
        radius *= scaleFactor;
        CalculateVolume();
    }
    void ShowInfo() override {
        std::cout << "Я сфера!" << std::endl;
        std::cout << "Мой объем = " << GetVolume() << std::endl;
        std::cout << "Мой радиус = " << radius << std::endl;
    }
    std::string GetName() const override { return "Sphere"; }
    void CalculateVolume() override {
        volume = (4.0f / 3.0f) * M_Pz`  I * pow(radius, 3);
    }
};