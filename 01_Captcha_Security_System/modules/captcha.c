#include <stdio.h>
#include <stdlib.h>  // rand() ফাংশন ব্যবহারের জন্য
#include <string.h>  // strcmp() ফাংশন ব্যবহারের জন্য
#include "captcha.h" // নিজস্ব হেডার ফাইলটি লিঙ্ক করলাম

// ক্যাপচা তৈরি করার ফাংশন
void generateCaptcha(char *captcha) {
    // ক্যাপচায় যেসব ক্যারেক্টার থাকতে পারবে তার একটা পুল বা অ্যারে
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int alphabetSize = sizeof(alphabet) - 1; // অ্যারের সাইজ বের করলাম (নাল ক্যারেক্টার বাদে)

    // লুপ চালিয়ে ৫টা র্যান্ডম ক্যারেক্টার সিলেক্ট করা
    for (int i = 0; i < CAPTCHA_LENGTH; i++) {
        int index = rand() % alphabetSize; // ০ থেকে alphabetSize এর মধ্যে একটি র্যান্ডম ইণ্ডেক্স নেওয়া
        captcha[i] = alphabet[index];     // ওই ইণ্ডেক্সের ক্যারেক্টারটি ক্যাপচা অ্যারেতে বসানো
    }
    captcha[CAPTCHA_LENGTH] = '\0'; // সি-স্ট্রিং এর নিয়ম অনুযায়ী শেষে নাল ক্যারেক্টার দিয়ে স্ট্রিং শেষ করা
}

// ক্যাপচা যাচাই করার ফাংশন
int verifyCaptcha(const char *secret, const char *user_input) {
    // strcmp দুটি স্ট্রিং হুবহু মিললে ০ রিটার্ন করে
    if (strcmp(secret, user_input) == 0) {
        return 1; // স্ট্রিং দুটি মিললে ১ (True) রিটার্ন করবে
    }
    return 0; // না মিললে ০ (False) রিটার্ন করবে
}