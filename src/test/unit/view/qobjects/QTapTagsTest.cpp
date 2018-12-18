#include "QTapTagsTest.h"
#include "view/qobjects/QTapTags.h"

namespace KegeratorDisplay {

QTapTagsTest::QTapTagsTest()
{
}

QTapTagsTest::~QTapTagsTest()
{
}

TEST_F(QTapTagsTest, Create)
{
    QTapTags tags;
}

TEST_F(QTapTagsTest, NameTagDefaultEmpty)
{
    QTapTags tags;
    EXPECT_EQ("", tags.nameTag());
}

TEST_F(QTapTagsTest, SetNameTag)
{
    QTapTags tags;
    tags.setNameTag("abc123");
}

TEST_F(QTapTagsTest, GetNameTag)
{
    QTapTags tags;
    tags.setNameTag("abc123");
    EXPECT_EQ("abc123", tags.nameTag());
}

TEST_F(QTapTagsTest, EstVolumeTagDefaultEmpty)
{
    QTapTags tags;
    EXPECT_EQ("", tags.estVolumeTag());
}

TEST_F(QTapTagsTest, SetEstVolumeTag)
{
    QTapTags tags;
    tags.setEstVolumeTag("Vol:");
}

TEST_F(QTapTagsTest, GetEstVolumeTag)
{
    QTapTags tags;
    tags.setEstVolumeTag("Vol:");
    EXPECT_EQ("Vol:", tags.estVolumeTag());
}

TEST_F(QTapTagsTest, BrewerTagDefaultEmpty)
{
    QTapTags tags;
    EXPECT_EQ("", tags.brewerTag());
}

TEST_F(QTapTagsTest, SetBrewerTag)
{
    QTapTags tags;
    tags.setBrewerTag("abc123");
}

TEST_F(QTapTagsTest, GetBrewerTag)
{
    QTapTags tags;
    tags.setBrewerTag("brewer:");
    EXPECT_EQ("brewer:", tags.brewerTag());
}

TEST_F(QTapTagsTest, AbvTagDefaultEmpty)
{
    QTapTags tags;
    EXPECT_EQ("", tags.abvTag());
}

TEST_F(QTapTagsTest, SetAbvTag)
{
    QTapTags tags;
    tags.setAbvTag("ABV");
}

TEST_F(QTapTagsTest, GetAbvTag)
{
    QTapTags tags;
    tags.setAbvTag("abv");
    EXPECT_EQ("abv", tags.abvTag());
}

TEST_F(QTapTagsTest, IbuTagDefaultEmpty)
{
    QTapTags tags;
    EXPECT_EQ("", tags.ibuTag());
}

TEST_F(QTapTagsTest, SetIbuTag)
{
    QTapTags tags;
    tags.setIbuTag("ibu");
}

TEST_F(QTapTagsTest, GetIbuTag)
{
    QTapTags tags;
    tags.setIbuTag("ibu");
    EXPECT_EQ("ibu", tags.ibuTag());
}

TEST_F(QTapTagsTest, BrewDateTagDefaultEmpty)
{
    QTapTags tags;
    EXPECT_EQ("", tags.brewDateTag());
}

TEST_F(QTapTagsTest, SetBrewDateTag)
{
    QTapTags tags;
    tags.setBrewDateTag("abc123");
}

TEST_F(QTapTagsTest, GetBrewDateTag)
{
    QTapTags tags;
    tags.setBrewDateTag("abc123");
    EXPECT_EQ("abc123", tags.brewDateTag());
}

TEST_F(QTapTagsTest, TapDateTagDefaultEmpty)
{
    QTapTags tags;
    EXPECT_EQ("", tags.tapDateTag());
}

TEST_F(QTapTagsTest, SetTapDateTag)
{
    QTapTags tags;
    tags.setTapDateTag("abc123");
}

TEST_F(QTapTagsTest, GetTapDateTag)
{
    QTapTags tags;
    tags.setTapDateTag("abc123");
    EXPECT_EQ("abc123", tags.tapDateTag());
}

TEST_F(QTapTagsTest, FinalGravityTagDefaultEmpty)
{
    QTapTags tags;
    EXPECT_EQ("", tags.finalGravityTag());
}

TEST_F(QTapTagsTest, SetFinalGravityTag)
{
    QTapTags tags;
    tags.setFinalGravityTag("abc123");
}

TEST_F(QTapTagsTest, GetFinalGravityTag)
{
    QTapTags tags;
    tags.setFinalGravityTag("abc123");
    EXPECT_EQ("abc123", tags.finalGravityTag());
}

TEST_F(QTapTagsTest, SaveButtonTagDefaultEmpty)
{
    QTapTags tags;
    EXPECT_EQ("", tags.saveButtonTag());
}

TEST_F(QTapTagsTest, SetSaveButtonTag)
{
    QTapTags tags;
    tags.setSaveButtonTag("abc123");
}

TEST_F(QTapTagsTest, GetSaveButtonTag)
{
    QTapTags tags;
    tags.setSaveButtonTag("abc123");
    EXPECT_EQ("abc123", tags.saveButtonTag());
}

TEST_F(QTapTagsTest, ClearButtonTagDefaultEmpty)
{
    QTapTags tags;
    EXPECT_EQ("", tags.clearButtonTag());
}

TEST_F(QTapTagsTest, SetClearButtonTag)
{
    QTapTags tags;
    tags.setClearButtonTag("abc123");
}

TEST_F(QTapTagsTest, GetClearButtonTag)
{
    QTapTags tags;
    tags.setClearButtonTag("abc123");
    EXPECT_EQ("abc123", tags.clearButtonTag());
}

}
