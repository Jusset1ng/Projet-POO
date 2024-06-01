#pragma once
#include <iostream>

class SupportADessin;

class Dessinable{
public:
virtual void dessine_sur(SupportADessin& support)=0;};
