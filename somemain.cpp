#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

//global variable for comparing
//We will use a class and overload operators in later assignments for this.
int compareId = -1;

struct RatingInformation
{
    int userId;
    int movieId;
    int rating;
};

list<RatingInformation> readFromFile(char* file)
{
    ifstream in_file;
    in_file.open(file);
    list<RatingInformation> ratings;
    
    while (!in_file.fail())
    {
        RatingInformation ratingInformation;
        in_file >> ratingInformation.userId;
        
        if (in_file.fail())
        {
            break;
        }
        
        in_file >> ratingInformation.movieId;
        in_file >> ratingInformation.rating;
        ratings.push_front(ratingInformation);
    }
    
    in_file.close();
    return ratings;
}

template<class InputIterator>
void print(InputIterator start, InputIterator finish)
{
    for (InputIterator current = start; current != finish; current++)
    {
        cout << "Userid is " << current->userId << " , MovieId is " << current->movieId << " , and rating is " << current->rating << endl;
    }
}

bool IsMatching(RatingInformation rating)
{
    return rating.userId != compareId;
}

template<class InputIterator>
bool containsMovie(InputIterator userStart, InputIterator userEnd, int movieId)
{
    for (InputIterator rating = userStart; rating != userEnd; rating++) 
    {
        if ((*rating).movieId == movieId)
        {
            return true;
        }
    }
    
    return false;
}

template<class InputIterator>
vector<RatingInformation> getSubset(InputIterator user1Start, InputIterator user1Finish, InputIterator user2Start, InputIterator user2Finish)
{
    vector<RatingInformation> overlappingRatings;
    for (InputIterator rating = user1Start; rating != user1Finish; rating++)
    {
        if (containsMovie(user2Start, user2Finish, (*rating).movieId))
        {
            overlappingRatings.push_back(*rating);
        }
    }
    
    return overlappingRatings;
}

void transform(vector<RatingInformation>& user, int shift)
{
    for (vector<RatingInformation>::iterator rating = user.begin(); rating != user.end(); rating++)
    {
        (*rating).rating = (*rating).rating + shift;
    }
}

bool ratingsComparer(RatingInformation r1, RatingInformation r2)
{
    return r1.movieId < r2.movieId;
}

int dotProduct(const vector<RatingInformation>& user1, const vector<RatingInformation>& user2)
{
    int dot = 0;
    for (int i = 0; i < user1.size(); i++)
    {
        dot = dot + user1.at(i).rating * user2.at(i).rating;
    }
    
    return dot;
}

int computeSimilarity(list<RatingInformation> ratings, int user1, int user2)
{
    compareId = user1;
    int size1 = count_if(ratings.begin(), ratings.end(), IsMatching);
    vector<RatingInformation> user1Ratings(ratings.size() - size1);
    remove_copy_if(ratings.begin(), ratings.end(), user1Ratings.begin(), IsMatching);
    
    compareId = user2;
    int size2 = count_if(ratings.begin(), ratings.end(), IsMatching);
    vector<RatingInformation> user2Ratings(ratings.size() - size2);
    remove_copy_if(ratings.begin(), ratings.end(), user2Ratings.begin(), IsMatching);

    vector<RatingInformation> user1Overlap = getSubset(user1Ratings.begin(), user1Ratings.end(), user2Ratings.begin(), user2Ratings.end());
    vector<RatingInformation> user2Overlap = getSubset(user2Ratings.begin(), user2Ratings.end(), user1Ratings.begin(), user1Ratings.end());
    
    transform(user1Overlap, -5);
    transform(user2Overlap, -5);
    
    sort(user1Overlap.begin(), user1Overlap.end(), ratingsComparer);
    sort(user2Overlap.begin(), user2Overlap.end(), ratingsComparer);
    
    return dotProduct(user1Overlap, user2Overlap);
}

int main (int argc, char * const argv[]) {
  list<RatingInformation> ratings = readFromFile("TestFile.txt");
    print(ratings.begin(), ratings.end());
    cout << computeSimilarity(ratings, 2, 1);
    return 0;
}