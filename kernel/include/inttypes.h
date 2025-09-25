#ifndef __INTTYPES_H__
#define __INTTYPES_H__

#define PRId32 "d"
#define PRIdLEAST32 "d"
#define PRIdFAST32 "d"

#define PRIi32 "i"
#define PRIiLEAST32 "i"
#define PRIiFAST32 "i"

#define PRIu32 "u"
#define PRIuLEAST32 "u"
#define PRIuFAST32 "u"

#define PRIo32 "o"
#define PRIoLEAST32 "o"
#define PRIoFAST32 "o"

#define PRIx32 "x"
#define PRIxLEAST32 "x"
#define PRIxFAST32 "x"

#define PRIX32 "X"
#define PRIXLEAST32 "X"
#define PRIXFAST32 "X"

#define PRId64 "l" PRId32
#define PRIdLEAST64 "l" PRIdLEAST32
#define PRIdFAST64 "l" PRIdFAST32

#define PRIi64 "l" PRIi32
#define PRIiLEAST64 "l" PRIiLEAST32
#define PRIiFAST64 "l" PRIiFAST32

#define PRIu64 "l" PRIu32
#define PRIuLEAST64 "l" PRIuLEAST32
#define PRIuFAST64 "l" PRIuFAST32

#define PRIo64 "l" PRIo32
#define PRIoLEAST64 "l" PRIoLEAST32
#define PRIoFAST64 "l" PRIoFAST32

#define PRIx64 "l" PRIx32
#define PRIxLEAST64 "l" PRIxLEAST32
#define PRIxFAST64 "l" PRIxFAST32

#define PRIX64 "l" PRIX32
#define PRIXLEAST64 "l" PRIXLEAST32
#define PRIXFAST64 "l" PRIXFAST32

#define PRId16 "h" PRId32
#define PRIdLEAST16 "h" PRIdLEAST32
#define PRIdFAST16 "h" PRIdFAST32

#define PRIi16 "h" PRIi32
#define PRIiLEAST16 "h" PRIiLEAST32
#define PRIiFAST16 "h" PRIiFAST32

#define PRIu16 "h" PRIu32
#define PRIuLEAST16 "h" PRIuLEAST32
#define PRIuFAST16 "h" PRIuFAST32

#define PRIo16 "h" PRIo32
#define PRIoLEAST16 "h" PRIoLEAST32
#define PRIoFAST16 "h" PRIoFAST32

#define PRIx16 "h" PRIx32
#define PRIxLEAST16 "h" PRIxLEAST32
#define PRIxFAST16 "h" PRIxFAST32

#define PRIX16 "h" PRIX32
#define PRIXLEAST16 "h" PRIXLEAST32
#define PRIXFAST16 "h" PRIXFAST32

#define PRId8 "hh" PRId32
#define PRIdLEAST8 "hh" PRIdLEAST32
#define PRIdFAST8 "hh" PRIdFAST32

#define PRIi8 "hh" PRIi32
#define PRIiLEAST8 "hh" PRIiLEAST32
#define PRIiFAST8 "hh" PRIiFAST32

#define PRIu8 "hh" PRIu32
#define PRIuLEAST8 "hh" PRIuLEAST32
#define PRIuFAST8 "hh" PRIuFAST32

#define PRIo8 "hh" PRIo32
#define PRIoLEAST8 "hh" PRIoLEAST32
#define PRIoFAST8 "hh" PRIoFAST32

#define PRIx8 "hh" PRIx32
#define PRIxLEAST8 "hh" PRIxLEAST32
#define PRIxFAST8 "hh" PRIxFAST32

#define PRIX8 "hh" PRIX32
#define PRIXLEAST8 "hh" PRIXLEAST32
#define PRIXFAST8 "hh" PRIXFAST32

#define PRIdMAX PRId64
#define PRIiMAX PRIi64
#define PRIuMAX PRIu64
#define PRIoMAX PRIo64
#define PRIxMAX PRIx64
#define PRIXMAX PRIX64

#define PRIdPTR PRId64
#define PRIiPTR PRIi64
#define PRIuPTR PRIu64
#define PRIoPTR PRIo64
#define PRIxPTR PRIx64
#define PRIXPTR PRIX64

#endif
