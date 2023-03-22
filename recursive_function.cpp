#include <iostream>
#include <list>

class YouTubeChannel 
{
private:
    std::string Name;
    int SubscribersCount;
    std::list<std::string> PublishedVideoTitles;
protected:
    std::string OwnerName;
    int ContentQuality;
public:
        YouTubeChannel(std::string name, std::string ownerName)
        {
            Name = name;
            OwnerName = ownerName;
            SubscribersCount = 0;
            ContentQuality = 0;
        }
        void GetInfo()
        {
            std::cout << "Name: " << Name << std::endl;
            std::cout << "OwnerName: " << OwnerName << std::endl;
            std::cout << "SubscribersCount: " << SubscribersCount << std::endl;
            for(std::string videoTitle : PublishedVideoTitles)
            {
                std::cout << videoTitle << std::endl;
            }
        }
        void Subscribe()
        {
            SubscribersCount++;
        }
        void Unsubscribe()
        {
            if(SubscribersCount > 0)
                SubscribersCount--;
        }
        void PublishedVideo(std::string title)
        {
            PublishedVideoTitles.push_back(title);
        }
        void CheckAnalytics()
        {
            if(ContentQuality < 5)
                std::cout << Name << " has bad quality content." << std::endl;
            else 
                std::cout << Name << " has great content." << std::endl;
        }
};

class CookingYouTubeChannel:public YouTubeChannel
{
public:    
    CookingYouTubeChannel(std::string name, std::string ownerName): YouTubeChannel(name, ownerName)
    {

    }
    void Practice()
    {
        std::cout << OwnerName << "practicing cooking, learning new recipes..." << std::endl;
        ContentQuality++;
    }
};
class SingersYouTubeChannel : public YouTubeChannel 
{
public: 
    SingersYouTubeChannel(std::string name, std::string ownerName) :YouTubeChannel(name, ownerName) 
    {

    }
    void Practice()
    {
        std::cout << OwnerName << " is taking classes, learning new songs, learning how to dance..." << std::endl;
        ContentQuality++;
    }
};

int main()
{
    CookingYouTubeChannel cookingYtChannel("Amy's Kitchen", "Amy");
    SingersYouTubeChannel singersYtChannel("John sings", "John");

    cookingYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();
    singersYtChannel.Practice();

    YouTubeChannel * yt1 = &cookingYtChannel;
    YouTubeChannel * yt2 = &singersYtChannel;

    yt1->CheckAnalytics();
    yt2->CheckAnalytics();

    return 0;
}

