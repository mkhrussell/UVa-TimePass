#include <cstdio>
#include <cstring>

char _dict[20000][30];

int _dict_size;
int _col_size;

char _result[30];
int _result_cursor = 0;

void addToResult(char searchKey)
{
    bool keyFound = false;
    for(int i = 0; i < _result_cursor; i++)
    {
        if(_result[i] == searchKey)
        {
            keyFound = true;
        }
    }

    if(!keyFound)
    {
        _result[_result_cursor++] = searchKey;
        _result[_result_cursor] = '\0';
    }
}

int main(int argc, char **argv)
{
    _dict_size = 0;
    _col_size = 0;
    while(fgets(_dict[_dict_size], 30, stdin))
    {
        if (strcmp(_dict[_dict_size], "#") == 0 || strcmp(_dict[_dict_size], "#\n") == 0)
        {
            break;
        }

        _col_size = strlen(_dict[_dict_size]) > _col_size ? strlen(_dict[_dict_size]) : _col_size;
        ++_dict_size;
    }

    for(int col = 0; col < _col_size; col++)
    {
        for(int row = 0; row < _dict_size; row++)
        {
            if(_dict[row][col] >= 'A' && _dict[row][col] <= 'Z')
            {
                addToResult(_dict[row][col]);
            }
        }
    }

    printf("%s\n", _result);

    return 0;
}
