#include "DSM.h"
#include <cassert>
//
//void test_constr2(){
//    string myElements[9] = {"CPU", "GPU", "RAM", "Motherboard", "PSU", "InDEV", "OutDEV", "SpecialDEV", "IOController"};
//    DSM s(myElements, 9);
//
//    s.addLink("Motherboard", "CPU", 1);
//    s.addLink("Motherboard", "GPU", 1);
//    s.addLink("Motherboard", "RAM", 1);
//    s.addLink("Motherboard", "PSU", 1);
//    s.addLink("Motherboard", "InDEV", 1);
//    s.addLink("Motherboard", "OutDEV", 1);
//    s.addLink("GPU", "PSU", 2);
//    s.addLink("CPU", "SpecialDEV", 3);
//    s.addLink("InDEV", "IOController", 3);
//    s.addLink("OutDEV", "IOController", 3);
//    assert(s.hasLink("GPU", "PSU") == true);
//    assert(s.linkWeight("GPU", "PSU") == 2);
//    assert(s.countToLinks("GPU") == 1);
//    assert(s.countFromLinks("GPU") == 1);
//    assert(s.countAllLinks() == 10);
//}
//void test_constr1(){
//        DSM destr(5);
//
//    destr.setElementName(0, "a");
//    destr.setElementName(1, "b");
//    destr.setElementName(2, "c");
//    destr.setElementName(3, "d");
//    destr.setElementName(4, "e");
//    destr.setElementName(5, "f");
//    assert (destr.size() == 6);
//    assert (destr.getName(1) == "b");
//
//    destr.addLink("c", "e", 1);
//    destr.addLink("a", "c", 1);
//    destr.addLink("e", "g", 8);
//
//    assert(destr.hasLink("GPU", "PSU") == true);
//    assert(destr.linkWeight("GPU", "PSU") == 2);
//    assert(destr.countToLinks("GPU") == 1);
//    assert(destr.countFromLinks("GPU") == 1);
//    assert(destr.countAllLinks() == 10);
//}