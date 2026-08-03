#define REG_DISPCNT *(volatile unsigned short*)0x4000000
#define VRAM ((volatile unsigned short*)0x6000000)
#define KEYS *(volatile unsigned short*)0x04000130

#define MODE3 3
#define BG2_ENABLE (1 << 10)
#define BUTTON_A (1 << 0)

#define SCREEN_W 240
#define SCREEN_H 160

// ألوان RGB للـ GBA
#define RGB(r, g, b) ((r) | ((g) << 5) | ((b) << 10))

#define C_TRANS 0xFFFF  // لون شفاف
#define C_BG    RGB(2, 3, 8)     // خلفية أزرق غامق جداً
#define C_BLK   RGB(0, 0, 0)     // أسود
#define C_YEL   RGB(31, 31, 0)   // أصفر ساطع
#define C_RED   RGB(31, 2, 2)    // أحمر شوكة
#define C_DRED  RGB(15, 0, 0)    // أحمر غامق
#define C_WHT   RGB(31, 31, 31)  // أبيض
#define C_LINE  RGB(0, 20, 25)   // لون الأرضية

// 1. سكن اللاعب: مكعب Geometry Dash بكسل (12x12)
const unsigned short player_skin[144] = {
    C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK,
    C_BLK, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_BLK,
    C_BLK, C_YEL, C_BLK, C_BLK, C_YEL, C_YEL, C_YEL, C_YEL, C_BLK, C_BLK, C_YEL, C_BLK,
    C_BLK, C_YEL, C_BLK, C_BLK, C_YEL, C_YEL, C_YEL, C_YEL, C_BLK, C_BLK, C_YEL, C_BLK,
    C_BLK, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_BLK,
    C_BLK, C_YEL, C_YEL, C_YEL, C_YEL, C_BLK, C_BLK, C_YEL, C_YEL, C_YEL, C_YEL, C_BLK,
    C_BLK, C_YEL, C_YEL, C_YEL, C_YEL, C_BLK, C_BLK, C_YEL, C_YEL, C_YEL, C_YEL, C_BLK,
    C_BLK, C_YEL, C_BLK, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_BLK, C_YEL, C_BLK,
    C_BLK, C_YEL, C_YEL, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_YEL, C_YEL, C_BLK,
    C_BLK, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_BLK,
    C_BLK, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_YEL, C_BLK,
    C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK, C_BLK
};

// 2. سكن العقبة: شوكة مثلثية (12x12)
const unsigned short spike_skin[144] = {
    C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_DRED,  C_DRED,  C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_TRANS,
    C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_DRED,  C_RED,   C_RED,   C_DRED,  C_TRANS, C_TRANS, C_TRANS, C_TRANS,
    C_TRANS, C_TRANS, C_TRANS, C_TRANS, C_DRED,  C_RED,   C_RED,   C_DRED,  C_TRANS, C_TRANS, C_TRANS, C_TRANS,
    C_TRANS, C_TRANS, C_TRANS, C_DRED,  C_RED,   C_RED,   C_RED,   C_RED,   C_DRED,  C_TRANS, C_TRANS, C_TRANS,
    C_TRANS, C_TRANS, C_TRANS, C_DRED,  C_RED,   C_RED,   C_RED,   C_RED,   C_DRED,  C_TRANS, C_TRANS, C_TRANS,
    C_TRANS, C_TRANS, C_DRED,  C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_DRED,  C_TRANS, C_TRANS,
    C_TRANS, C_TRANS, C_DRED,  C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_DRED,  C_TRANS, C_TRANS,
    C_TRANS, C_DRED,  C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_DRED,  C_TRANS,
    C_TRANS, C_DRED,  C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_DRED,  C_TRANS,
    C_DRED,  C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_DRED,
    C_DRED,  C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_RED,   C_DRED,
    C_DRED,  C_DRED,  C_DRED,  C_DRED,  C_DRED,  C_DRED,  C_DRED,  C_DRED,  C_DRED,  C_DRED,  C_DRED,  C_DRED
};

void waitForVBlank() {
    volatile unsigned short* scanline = (volatile unsigned short*)0x4000006;
    while (*scanline < 160);
    while (*scanline >= 160);
}

// رسم مستطيل بلون ثابت
void drawRect(int x, int y, int w, int h, unsigned short color) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int drawX = x + j;
            int drawY = y + i;
            if (drawX >= 0 && drawX < SCREEN_W && drawY >= 0 && drawY < SCREEN_H) {
                VRAM[drawY * SCREEN_W + drawX] = color;
            }
        }
    }
}

// رسم سكن (Sprite) مع مراعاة الشفافية
void drawSprite(int x, int y, int w, int h, const unsigned short* sprite) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            unsigned short color = sprite[i * w + j];
            if (color != C_TRANS) { // تجاوز اللون الشفاف
                int drawX = x + j;
                int drawY = y + i;
                if (drawX >= 0 && drawX < SCREEN_W && drawY >= 0 && drawY < SCREEN_H) {
                    VRAM[drawY * SCREEN_W + drawX] = color;
                }
            }
        }
    }
}

int main() {
    REG_DISPCNT = MODE3 | BG2_ENABLE;

    int playerX = 30;
    int playerY = 110;
    int playerSize = 12;
    int velY = 0;
    int gravity = 1;
    int isGrounded = 1;

    int obsX = 230;
    int obsY = 110; // محاذاة الشوكة مع الأرض
    int obsW = 12;
    int obsH = 12;
    int obsSpeed = 3;

    int groundY = 122;

    while (1) {
        waitForVBlank();

        // 1. مسح الشاشة باللون الأزرق الغامق
        drawRect(0, 0, SCREEN_W, SCREEN_H, C_BG);

        // 2. التحكم (زر A)
        if (!(KEYS & BUTTON_A) && isGrounded) {
            velY = -8;
            isGrounded = 0;
        }

        // 3. الفيزياء
        playerY += velY;
        velY += gravity;

        if (playerY >= groundY - playerSize) {
            playerY = groundY - playerSize;
            velY = 0;
            isGrounded = 1;
        }

        // 4. تحريك الشوكة
        obsX -= obsSpeed;
        if (obsX < -obsW) {
            obsX = SCREEN_W;
        }

        // 5. الاصطدام (Hitbox أصغر قليلاً لجعل اللعبة عادلة مع الشوكة)
        if (playerX + 2 < obsX + obsW - 2 &&
            playerX + playerSize - 2 > obsX + 2 &&
            playerY + 2 < obsY + obsH &&
            playerY + playerSize > obsY + 2) {
            
            obsX = SCREEN_W;
            playerY = groundY - playerSize;
            velY = 0;
        }

        // 6. رسم الأرضية والسكنات
        drawRect(0, groundY, SCREEN_W, 38, C_LINE);               // الأرضية
        drawRect(0, groundY, SCREEN_W, 2, C_WHT);                 // خط الأرض الأبيض
        drawSprite(playerX, playerY, 12, 12, player_skin);       // سكن المكعب
        drawSprite(obsX, obsY, 12, 12, spike_skin);               // سكن الشوكة
    }

    return 0;
}
