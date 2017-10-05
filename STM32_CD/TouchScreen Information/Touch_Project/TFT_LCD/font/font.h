// Font data for Lucida Console 12pt

// ��������� ������� � ������� �������� ��������
typedef struct FontTable
{
 uint16_t width;           // ������ �������
 uint16_t start;           // ��������� ������ �� ������ ���� ������� � ������� ������ ��������
} FONT_CHAR_INFO;

// ��������� ��� ������� � ���������� ������������� ������
typedef struct
{
 uint8_t Height;                        // ������ ��������
 uint8_t FirstChar;                     // ������ ������� �������
 uint8_t LastChar;                      // ������ ���������� �������
 uint8_t FontSpace;                     // ������ ����� ���������
 const FONT_CHAR_INFO *FontTable;    // ������� �������� ��������
 const uint8_t *FontBitmaps;            // ��������� �� ������ � ������� � ��������
} FONT_INFO;
