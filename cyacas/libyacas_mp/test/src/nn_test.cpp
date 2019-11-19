/*
 *
 * This file is part of yacas.
 * Yacas is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesset General Public License as
 * published by the Free Software Foundation, either version 2.1
 * of the License, or (at your option) any later version.
 *
 * Yacas is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with yacas.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "yacas/mp/zz.hpp"

#include <gtest/gtest.h>

using namespace yacas::mp;

TEST(YMP_NNTest, construction)
{
    ASSERT_TRUE(NN("0").is_zero());
    ASSERT_EQ(NN("123"), NN(123u));
    ASSERT_EQ(NN(" 123"), NN(123u));
    ASSERT_EQ(NN("FF", 16), NN("255"));
    ASSERT_EQ(NN("ff", 16), NN("255"));
    ASSERT_EQ(NN("deadbeef", 16), NN("3735928559"));
    ASSERT_THROW(NN(""), NN::ParseError);
    ASSERT_THROW(NN(" "), NN::ParseError);
    ASSERT_THROW(NN("deadbeef", 15), NN::ParseError);
}

TEST(YMP_NNTest, is_zero)
{
    ASSERT_TRUE(NN(0u).is_zero());
    ASSERT_FALSE(NN(1u).is_zero());
    ASSERT_FALSE(NN("4294967296").is_zero());
}

TEST(YMP_NNTest, comparison)
{
    ASSERT_TRUE(NN("735") == NN(735u));
    ASSERT_TRUE(NN("736") != NN("735"));
    ASSERT_TRUE(NN("736") > NN("735"));
    ASSERT_TRUE(NN("736") >= NN("735"));
}

TEST(YMP_NNTest, parity)
{
    ASSERT_TRUE(NN(0u).is_even());
    ASSERT_FALSE(NN(1u).is_even());
    ASSERT_TRUE(NN(2u).is_even());
    ASSERT_FALSE(NN(3u).is_even());
}

TEST(YMP_NNTest, to_string)
{
    ASSERT_EQ(NN(0u).to_string(10), "0");
    ASSERT_EQ(NN(1u).to_string(10), "1");
    ASSERT_EQ(NN(2u).to_string(10), "2");
    ASSERT_EQ(NN("18446744073709551616").to_string(), "18446744073709551616");

    ASSERT_EQ(
        NN("121932631356500531591068431703703700581771069347203169112635269")
            .to_string(),
        "121932631356500531591068431703703700581771069347203169112635269");

    ASSERT_EQ(NN("3735928559").to_string(16), "deadbeef");

    ASSERT_EQ(
        NN("121932631356500531591068431703703700581771069347203169112635269")
            .to_string(),
        "121932631356500531591068431703703700581771069347203169112635269");
}


TEST(YMP_NNTest, shift)
{
    NN a;

    a = NN(5);
    a <<= 1;
    ASSERT_EQ(a, NN(10));

    a = NN(5);
    a >>= 1;
    ASSERT_EQ(a, NN(2));

    a = NN("121932631356500531591068431703703700581771069347203169112635268");
    a >>= 1;
    ASSERT_EQ(
        a,
        NN("60966315678250265795534215851851850290885534673601584556317634"));
}

TEST(YMP_NNTest, sqr)
{
    NN a;

    a = NN(5);
    a.sqr();
    ASSERT_EQ(a, NN("25"));

    a = NN("1562953088685537097059913193583733507649747348170814625952201");
    a.sqr();
    ASSERT_EQ(
        a,
        NN("2442822357431660390046655205292608987306861461763843847861569410791"
           "671541750358984338534812651100785465086339385936744401"));

    a = NN("1667703557600363725046376676090748681843605861855768202333970544912"
           "5918899");
    a.sqr();
    ASSERT_EQ(a,
              NN("2781235156032909688867661347708318236031357056471990889749656"
                 "8874577914400268908763247285607086599717046124954345677502282"
                 "2347627260616871125372201"));
    a.sqr();
    ASSERT_EQ(a,
              NN("7735268993153403503304606191118795696610949078309176540718091"
                 "8697187558629814838215212696461020230376125043081229650956490"
                 "7199281643513660336004802212689814512583461474131759251703924"
                 "1448510014854449620623685195394076123932122239019841816567816"
                 "5748977200849860077295483412916485724330783584401"));

    a = NN("43298432840974328947183271491541079320475403764598753914325843075329"
           "85041258796438702654310726508743652874365432087655736345012364756043"
           "81753408315620873167430821540810560872643218756743810564783105825648"
           "74056087436587431065731486504375673456743053247885032856087432065310"
           "87564398204357520436574325863520007434365308725624380653765208734132"
           "46475659873589327902573743285932585467423285984375932575852094237923"
           "579328");

    a.sqr();
    ASSERT_EQ(a,
              NN("187475428648436429856831489259327536436520448042946087510189029"
                 "508938780965513552632980143411535002947654949460620663344635790"
                 "556377422365029345765733894771796962944560922729298314258140552"
                 "929369408117002607439027128831914911354137217799235321698085404"
                 "005442143761335597185337908611893721164171813516683980879772274"
                 "862485082671460833262731384783122158289313793496453424229418477"
                 "994889974902044275544841799735966023054440842435704344714181994"
                 "613927594359524428405377856257194202888469364705167511792141640"
                 "532726328300226911110011094535694877421493842649850484322056237"
                 "900295096809510203923061353581327350260262295074165065947916753"
                 "169818423862934362386660760025589538715872105323918909971201848"
                 "819723597348997720621263653492740044130493923227011660433942814"
                 "829917409985490369529307633336067725045689754286184615455264247"
                 "108931584"));

    NN b{a};
    a.sqr();
    b *= b;
    ASSERT_EQ(a, b);
    a.sqr();
    b *= b;
    ASSERT_EQ(a, b);
}

TEST(YMP_NNTest, mul)
{
    NN a(10);
    a *= 10;
    ASSERT_EQ(a, NN(100));
    a *= 10;
    ASSERT_EQ(a, NN(1000));
    a *= 10;
    ASSERT_EQ(a, NN(10000));
    a *= 100;
    ASSERT_EQ(a, NN(1000000));
    a *= 100;
    ASSERT_EQ(a, NN(100000000));
    a *= 100;
    ASSERT_EQ(a, NN("10000000000"));
    a *= 100;
    ASSERT_EQ(a, NN("1000000000000"));
    a *= 100;
    ASSERT_EQ(a, NN("100000000000000"));
    a *= 753;
    ASSERT_EQ(a, NN("75300000000000000"));
    NN b(10);
    a *= b;
    ASSERT_EQ(a, NN("753000000000000000"));

    NN x("4294967296");
    NN y("4294967296");
    x *= y;
    ASSERT_EQ(x, NN("18446744073709551616"));

    x = NN("123456789123456789123456789");
    y = NN("987654321987654321987654321987654321");
    x *= y;
    ASSERT_EQ(
        x,
        NN("121932631356500531591068431703703700581771069347203169112635269"));
}

TEST(YMP_NNTest, pow)
{
    NN a("1234567890123456789");

    a.pow(7);
    ASSERT_EQ(
        a,
        NN("4371241899268725428364208289519510588539212553598950486912858825153"
           "547618526426094549436384682321156604105518810510686881926429"));
}

TEST(YMP_NNTest, div_rem)
{
    NN a(123);

    ASSERT_THROW(a /= 0, std::domain_error);
    ASSERT_EQ(a /= 1, NN(123));
    ASSERT_EQ(a /= 123, NN::ONE);
    a = NN("123");
    ASSERT_EQ(a /= 10, NN(12));
    ASSERT_EQ(a /= 6, NN(2));

    a = NN("12314324325435664576576568787687576435342431432545345");
    a /= 743;
    ASSERT_EQ(a, NN("16573787786589050574127279660413965592654685642725"));
    a = NN(123);

    ASSERT_THROW(a /= NN::ZERO, std::domain_error);
    ASSERT_EQ((a /= NN(1)), NN(123));
    ASSERT_EQ((a /= NN(123)), NN::ONE);
    a = NN("123");
    ASSERT_EQ((a /= NN(10)), NN(12));
    ASSERT_EQ((a /= NN(6)), NN(2));
    a = NN("1125899906842624");
    NN b("562949953421312");
    a /= b;
    ASSERT_EQ(a, NN::TWO);
    a = NN("79228162514264337593543950335");
    b = NN("39614081257132168796771975168");
    a /= b;
    ASSERT_EQ(a, NN::ONE);
    a = NN("79228162514264337593543950336");
    b = NN("39614081257132168796771975168");
    a /= b;
    ASSERT_EQ(a, NN::TWO);
    a = NN("12314324325435664576576568787687576435342431432545345");
    b = NN("42345346452431432543645634543455434");
    a /= b;
    ASSERT_EQ(a, NN("290807027385380782"));

    a = NN(1);
    for (int i = 1; i <= 20; ++i)
        a *= NN(i);
    b = NN(1);
    for (int i = 1; i <= 10; ++i)
        b *= NN(i);
    a /= b;
    ASSERT_EQ(a, NN("670442572800"));

    a = NN(1);
    for (int i = 1; i <= 50; ++i)
        a *= NN(i);
    b = NN(1);
    for (int i = 1; i <= 40; ++i)
        b *= NN(i);
    a /= b;
    ASSERT_EQ(a, NN("37276043023296000"));

    a = NN(1);
    for (int i = 1; i <= 100; ++i)
        a *= NN(i);
    b = NN(1);
    for (int i = 1; i <= 90; ++i)
        b *= NN(i);
    a /= b;
    ASSERT_EQ(a, NN("62815650955529472000"));

    a = NN(1);
    for (int i = 1; i <= 150; ++i)
        a *= NN(i);
    b = NN(1);
    for (int i = 1; i <= 140; ++i)
        b *= NN(i);
    a /= b;
    ASSERT_EQ(a, NN("4244078637389118528000"));

    a = NN(1);
    for (int i = 1; i <= 180; ++i)
        a *= NN(i);

    ASSERT_EQ(
        a,
        NN("2008960624991342996569513368984668389175403407988677779404353351600"
           "4486095339598094118013811209730973563159410103739960967103213218633"
           "1495273609598531966730972945653558819806475064353856858157445040809"
           "2095603584633196446648911142564300178241417967538181923386423026933"
           "27818731986039603200000000000000000000000000000000000000000000"));

    b = NN(1);
    for (int i = 1; i <= 170; ++i)
        b *= NN(i);

    ASSERT_EQ(
        b,
        NN("7257415615307998967396728211129263114716991681296451376543577798900"
           "5618434017061578523507492426174595114909912378385207766660225654427"
           "5302532890077320751090240043028005829560396661259965825710439855829"
           "4257568966313439612262571094946806711205568880457193340212661452800"
           "000000000000000000000000000000000000000"));

    a /= b;
    ASSERT_EQ(a, NN("27681487894311318144000"));

    a = NN("1234567890123456789");
    b = NN("987654321");
    a /= b;
    ASSERT_EQ(a, NN("1249999988"));

    a = NN("281512773099640599001078059567905818350");
    b = NN("72873402435871630350805926803788103957");

    a /= b;
    ASSERT_EQ(a, NN("3"));

    a = NN("123456789012345678901234567890123456789012345678901234567890123456"
           "789012345678901234567890123456789012345678901234567890123456789012"
           "345678901234567890123456789012345678901234567890123456789012345678"
           "901234567890123456789012345678901234567890123456789012345678901234"
           "567890123456789012345678901234567890123456789012345678901234567890"
           "123456789012345678901234567890123456789012345678901234567890123456"
           "789012345678901234567890123456789012345678901234567890123456789012"
           "345678901234567890123456789012345678901234567890123456789012345678"
           "901234567890123456789012345678901234567890123456789012345678901234"
           "567890123456789012345678901234567890123456789012345678901234567890"
           "123456789012345678901234567890123456789012345678901234567890123456"
           "789012345678901234567890123456789012345678901234567890123456789012"
           "345678901234567890123456789012345678901234567890123456789012345678"
           "901234567890123456789012345678901234567890123456789012345678901234"
           "567890123456789012345678901234567890123456789012345678901234567890"
           "123456789012345678901234567890123456789012345678901234567890123456"
           "789012345678901234567890123456789012345678901234567890123456789012"
           "345678901234567890123456789012345678901234567890123456789012345678"
           "901234567890123456789012345678901234567890123456789012345678901234"
           "567890123456789012345678901234567890123456789012345678901234567890"
           "123456789012345678901234567890123456789012345678901234567890123456"
           "789012345678901234567890123456789012345678901234567890123456789012"
           "345678901234567890123456789012345678901234567890123456789012345678"
           "901234567890123456789012345678901234567890123456789012345678901234"
           "567890123456789012345678901234567890123456789012345678901234567890"
           "123456789012345678901234567890123456789012345678901234567890123456"
           "789012345678901234567890123456789012345678901234567890123456789012"
           "345678901234567890123456789012345678901234567890123456789012345678"
           "901234567890123456789012345678901234567890123456789012345678901234"
           "5678901234567890123456789012345678901234567890123456789012345678"
           "9");
    b = NN(
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "1234567890123456789012345678901234567890123456789012345678901234567890"
        "123456789");

    a /= b;

    ASSERT_EQ(a,
              NN("1000000000000000000000000000000000000000000000000000000000000"
                 "00000000000000000000"));

    a = NN("340282366920938463463374607431768211456");
    b = NN("4");
    a /= b;
    ASSERT_EQ(a, NN("85070591730234615865843651857942052864"));
    a = NN(3);
    a %= NN(2);
    ASSERT_EQ(a, NN("1"));

    a = NN("12314324325435664576576568787687576435342431432545345");
    a %= 743;
    ASSERT_EQ(a, NN(670));

    a = NN("1234567890123456789");
    b = NN("987654321");
    a %= b;
    ASSERT_EQ(a, NN("725308641"));

    a = NN("2618461302565558051873150214470675720371752830764642155368330885104190000");
    b = NN("141326557078049505524642968688");
    a /= b;
    ASSERT_EQ(a, NN("18527737155016642260898961793617744820333125"));
}

TEST(YMP_NNTest, bitwise) {}

TEST(YMP_NNTest, no_digits)
{
    ASSERT_EQ(NN().no_digits(), 1);
    ASSERT_EQ(NN("1234567890123456789").no_digits(), 19);
    ASSERT_EQ(
        NN("12314324325435664576576568787687576435342431432545345").no_digits(),
        53);
    NN a = NN(10);
    a.pow(93);
    ASSERT_EQ(a.no_digits(), 94);
    a -= 1;
    ASSERT_EQ(a.no_digits(), 93);
}

TEST(YMP_NNTest, gcd)
{
    NN a(6);
    NN b(4);

    NN c;

    c = gcd(a, b);

    ASSERT_EQ(c, NN(2));
}
