#define CATCH_CONFIG_MAIN
#include "../../testing/catch.hpp"
#include "string"
#include "../simple_class/class.h"
#include "../hard_class/class.h"
#include "sstream"

TEST_CASE("Simple_Constructors") {
    SECTION("Double_Constructor") {
        Triple_Signal a1((short) 1);
        REQUIRE(a1.get_state() == 1);

        Triple_Signal a2((short) 2);
        REQUIRE(a2.get_state() == 2);

        Triple_Signal a3((short) 3);
        REQUIRE(a3.get_state() == 2);

        Triple_Signal a4((short) 0);
        REQUIRE(a4.get_state() == 0);
    }
    SECTION("Char_Constructor") {
        Triple_Signal a1((char) '1');
        REQUIRE(a1.get_state() == 1);

        Triple_Signal a2((char) '2');
        REQUIRE(a2.get_state() == 2);

        Triple_Signal a3((char) '3');
        REQUIRE(a3.get_state() == 2);

        Triple_Signal a4((char) '0');
        REQUIRE(a4.get_state() == 0);

        Triple_Signal a5((char) 'X');
        REQUIRE(a5.get_state() == 2);
    }
}

TEST_CASE("String_Conversion") {
    Triple_Signal a1(short(1));
    REQUIRE(std::string(a1) == "State: 1\n");

    Triple_Signal a2(short(2));
    REQUIRE(std::string(a2) == "State: X\n");

    Triple_Signal a3(short(0));
    REQUIRE(std::string(a3) == "State: 0\n");
}

TEST_CASE("Console_Manipulation") {
    SECTION("CIN") {
        Triple_Signal a(short (0));
        std::stringstream in("1\n");
        a.cin(in);
        REQUIRE(a.get_state() == 1);

        std::stringstream in2("X\n");
        a.cin(in2);
        REQUIRE(a.get_state() == 2);

        std::stringstream in3("3\n");
        a.cin(in3);
        REQUIRE(a.get_state() == 2);

        std::stringstream in4("0\n");
        a.cin(in4);
        REQUIRE(a.get_state() == 0);

        std::stringstream in5("1");
        REQUIRE_THROWS(a.cin(in4));
        REQUIRE(a.get_state() == 0);
    }

    SECTION("COUT") {
        std::stringstream out1;
        Triple_Signal a1(short (0));
        a1.cout(out1);
        REQUIRE(out1.str() == "State: 0\n");

        std::stringstream out2;
        Triple_Signal a2(short (1));
        a2.cout(out2);
        REQUIRE(out2.str() == "State: 1\n");

        std::stringstream out3;
        Triple_Signal a3(short (2));
        a3.cout(out3);
        REQUIRE(out3.str() == "State: X\n");
    }
}

TEST_CASE("Getter_Setter") {
    SECTION("get_state_short") {
        Triple_Signal a1((short) 1);
        REQUIRE(a1.get_state() == 1);

        Triple_Signal a2((short) 2);
        REQUIRE(a2.get_state() == 2);

        Triple_Signal a3((short) 3);
        REQUIRE(a3.get_state() == 2);

        Triple_Signal a4((short) 0);
        REQUIRE(a4.get_state() == 0);
    }
    SECTION("get_state_char") {
        Triple_Signal a1((short) 1);
        REQUIRE(a1.get_state_char() == '1');

        Triple_Signal a2((short) 2);
        REQUIRE(a2.get_state_char() == 'X');

        Triple_Signal a3((short) 3);
        REQUIRE(a3.get_state_char() == 'X');

        Triple_Signal a4((short) 0);
        REQUIRE(a4.get_state_char() == '0');
    }

    SECTION("set_state_short") {
        Triple_Signal a((short) 0);
        a.set_state((short) 1);
        REQUIRE(a.get_state() == 1);

        a.set_state((short) 2);
        REQUIRE(a.get_state() == 2);

        a.set_state((short) 0);
        REQUIRE(a.get_state() == 0);

        a.set_state((short) 3);
        REQUIRE(a.get_state() == 2);
    }

    SECTION("set_state_char") {
        Triple_Signal a((short) 0);
        a.set_state((char) '1');
        REQUIRE(a.get_state() == 1);

        a.set_state((char) '2');
        REQUIRE(a.get_state() == 2);

        a.set_state((char) '0');
        REQUIRE(a.get_state() == 0);

        a.set_state((char) 'X');
        REQUIRE(a.get_state() == 2);
    }
}

TEST_CASE("Operations") {
    SECTION("OR") {
        Triple_Signal a((short) 0);
        Triple_Signal b((short) 0);

        Triple_Signal *result = a || b;
        REQUIRE(result->get_state() == 0);
        delete result;

        a.set_state((short) 1);
        b.set_state((short) 1);
        result = a || b;
        REQUIRE(result->get_state() == 1);
        delete result;

        a.set_state((short) 2);
        b.set_state((short) 0);
        result = a || b;
        REQUIRE(result->get_state() == 2);
        delete result;
    }
    SECTION("AND") {
        Triple_Signal a((short) 0);
        Triple_Signal b((short) 0);

        Triple_Signal *result = a && b;
        REQUIRE(result->get_state() == 0);
        delete result;

        a.set_state((short) 1);
        b.set_state((short) 1);
        result = a && b;
        REQUIRE(result->get_state() == 1);
        delete result;

        a.set_state((short) 2);
        b.set_state((short) 2);
        result = a && b;
        REQUIRE(result->get_state() == 2);
        delete result;
    }

    SECTION("NOT") {
        Triple_Signal a((short) 0);

        Triple_Signal *result = !a;
        REQUIRE(result->get_state() == 1);
        delete result;

        a.set_state((short) 1);
        result = !a;
        REQUIRE(result->get_state() == 0);
        delete result;

        a.set_state((short) 2);
        result = !a;
        REQUIRE(result->get_state() == 2);
        delete result;
    }

    SECTION("PRE_INC") {
        Triple_Signal a((short) 0);
        REQUIRE((++a).get_state() == 1);
        REQUIRE((++a).get_state() == 0);
        a.set_state('X');
        REQUIRE((++a).get_state() == 2);
        REQUIRE((++a).get_state() == 2);
    }
    SECTION("POST_INC") {
        Triple_Signal a((short) 0);
        REQUIRE((a++).get_state() == 0);
        REQUIRE((a++).get_state() == 1);
        a.set_state('X');
        REQUIRE((++a).get_state() == 2);
        REQUIRE((++a).get_state() == 2);
    }

    SECTION("COPY") {
        Triple_Signal a((short) 0);

        Triple_Signal *result = a.copy();
        REQUIRE(result->get_state() == 0);
        delete result;

        a.set_state((short) 1);
        result = a.copy();
        REQUIRE(result->get_state() == 1);
        delete result;

        a.set_state((short) 2);
        result = a.copy();
        REQUIRE(result->get_state() == 2);
        delete result;
    }
}

//TEST_CASE("Hard_Constructors") {
//    SECTION("Default") {
//        Triple_Array a;
//        REQUIRE(a.get_size() == 0);
//        REQUIRE(a.get_limit() == 0);
//    }
//    SECTION("Initializing constructor int") {
//        Triple_Array a(10);
//        REQUIRE(a.get_size() == 10);
//        REQUIRE(a.get_limit() == 10);
//        for (int i = 0; i < a.get_size(); i++) {
//            REQUIRE(a.get_array()[i]->get_state() == 2);
//        }
//    }
//    SECTION("Initializing constructor str") {
//        std::string s = "10101X010";
//        Triple_Array a(s);
//        REQUIRE(a.get_size() == s.length());
//        REQUIRE(a.get_limit() == s.length());
//        for (int i = 0; i < a.get_size(); i++) {
//            REQUIRE(a.get_array()[i]->get_state_char() == s[i]);
//        }
//        REQUIRE_THROWS(Triple_Array(INT_MAX + 1));
//    }
//}
