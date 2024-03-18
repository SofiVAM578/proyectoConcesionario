#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#pragma region Estructuras

string Clientes = "id; firt_name; last_name; email; age";
string Autos= "id; maker; model; year; sold_to; bought_to; sold_for; bought_for ";
struct Client {
	int id;
	string first_name;
	string last_name;
	string email;
	int age;
};
struct Seller {
	int id;
	string first_name;
	string last_name;
	string email;
	int age;
};
struct Car {
	int id;
	string maker;
	string model;
	int year;
	int sold_to;
	int bought_to;
	int sold_for;
	int bought_for;
};