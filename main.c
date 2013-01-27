/*
 * 使い方
 *   $ ./main csv形式のファイル名
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 256

// for debug
#if _UT
#define STATIC
#else
#define STATIC static
#endif

//STATIC int
STATIC void
_spCsv( char* row, unsigned int *csvNum, char *csvVal[MAX_SIZE] )
{
    csvVal[0] = strtok( row, "," );
    csvVal[1] = strtok( NULL, "," );
    csvVal[2] = strtok( NULL, "," );
    *csvNum = 3;
    #if 0
    for( tp = strtok( row, "," ); tp != NULL; tp = strtok( NULL, "," ) )
    {
        csvVal[]
    }
    #endif
}

int
main( int argc, char** argv )
{
    FILE    *_fp    = NULL;
    char    _row[MAX_SIZE];
    int     _ret   = 0;
    unsigned int    _csvNum = 0;
    char    *_csvVal[MAX_SIZE];
    unsigned int    i       = 0;

    if( 2 != argc )
    {
        printf("usage:./main filename\n");
        exit(EXIT_FAILURE);
    }

    // 初期化
    memset( _row, 0x00, sizeof( _row ) );
    memset( _csvVal, 0x00, sizeof( _csvVal ) );

    // ファイル読み込み
    _fp = fopen( argv[1], "r" );
    if( NULL == _fp )
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    /* 1行読み込んだとき、改行文字まで読み込まれる */
    /* サイズが1のとき、終端NULLのみ格納される */
    /* NULLが返却されたとき、全行読み込んだものとする */
    while( NULL !=  fgets( _row, MAX_SIZE, _fp ) )
    {
        printf("len _row = %d\n", sizeof(_row));
        if( _row[strlen(_row)-1] == '\n' )
        {
            printf("in if()\n");
            _row[strlen(_row)-1] = '\0';
        }
        // 1行を各要素に分解
        //_ret = _spCsv( _row, &_csvNum, &_csvVal );
        _spCsv( _row, &_csvNum, _csvVal );

        #if 0
        // メモリ確保エラー
        if( 0 != _ret )
        {
            printf("memory allocation error!\n");
            goto ERROR;
        }
        #endif

        // 読み込んだ文字を出力
        for( i = 0; i < _csvNum; i++ )
        {
            printf("_csvVal[%u]=(%s)\n", i, _csvVal[i] );
        }
    }

ERROR:
    fclose( _fp );

    return 0;

}
