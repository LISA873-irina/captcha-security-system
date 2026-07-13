#include <stdio.h>
#include <stdlib.h>
#include <time.h>    // time() ফাংশন ব্যবহারের জন্য (র্যান্ডম সিড দিতে লাগে)
#include "captcha.h" // আমাদের নিজস্ব ক্যাপচা হেডার ফাইল

int main() {
    char secretCaptcha[CAPTCHA_LENGTH + 1]; // সিস্টেমের জেনারেট করা ক্যাপচা রাখার অ্যারে
    char userAttempt[CAPTCHA_LENGTH + 1];   // ইউজারের দেওয়া ইনপুট রাখার অ্যারে

    // প্রতিবার রান করার সময় যেন একই ক্যাপচা বারবার না আসে, সেজন্য টাইম দিয়ে র্যান্ডম সিড (Seed) জেনারেট করা
    srand(time(NULL));
    
    // ক্যাপচা জেনারেট করে secretCaptcha অ্যারেতে সেভ করা
    generateCaptcha(secretCaptcha);

    printf("=== IUT SECURITY GATEWAY ===\n");
    printf("CAPTCHA: ");
    
    // ক্যাপচা কোডটি স্ক্রিনে একটা একটা ক্যারেক্টার করে স্পেস দিয়ে প্রিন্ট করা (যাতে দেখতে সুন্দর লাগে)
    for(int i = 0; i < CAPTCHA_LENGTH; i++) {
        printf("%c ", secretCaptcha[i]);
    }
    printf("\n============================\n");

    // ইউজারের কাছ থেকে ইনপুট নেওয়া
    printf("Enter the CAPTCHA code: ");
    scanf("%s", userAttempt);

    // আমাদের মডিউলের ভেরিফিকেশন ফাংশন কল করে চেক করা
    if (verifyCaptcha(secretCaptcha, userAttempt)) {
        printf("\n[SUCCESS] CAPTCHA Verified! Access Granted.\n");
    } else {
        printf("\n[ERROR] Invalid CAPTCHA! Access Denied.\n");
    }

    return 0;
}