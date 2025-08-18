/*
구현문제고, 답안보다 내가 더 잘 구현한 느낌?
*/

class RandomizedSet
{
public:
    RandomizedSet()
    {
        srand(time(NULL));
    }

    bool insert(int val)
    {
        if (us.count(val))
            return false;
        us.insert(val);
        return true;
    }

    bool remove(int val)
    {
        if (!us.count(val))
            return false;
        us.erase(val);
        return true;
    }

    int getRandom()
    {

        auto iter = us.begin();
        advance(iter, rand() % us.size());

        return *iter;
    }

private:
    unordered_set<int> us;
};