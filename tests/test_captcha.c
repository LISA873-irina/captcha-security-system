#include <stdio.h>
#include <string.h>
#include "captcha.h" // টেস্ট করার জন্য হেডার ফাইল ইনক্লুড করলাম

// টেস্ট ১: সঠিক ইনপুট দিলে ফাংশন ১ (True) দেয় কি না
int testVerification() {
    return verifyCaptcha("Ab123", "Ab123") == 1; // মিললে ১ আসবে, টেস্ট পাস হবে
}

// টেস্ট ২: ভুল ইনপুট দিলে ফাংশন ০ (False) দেয় কি না
int testFailure() {
    return verifyCaptcha("Ab123", "XyZ99") == 0; // না মিললে ০ আসবে, টেস্ট পাস হবে
}

int main() {
    printf("Running CAPTCHA Module Tests...\n");
    int passed = 0;  // কয়টা টেস্ট পাস হলো তার কাউন্টার
    int total = 0;   // টোটাল কয়টা টেস্ট রান হলো তার কাউন্টার

    total++;
    if (testVerification()) passed++; // টেস্ট ১ রান করলাম, পাস হলে কাউন্টার ১ বাড়বে

    total++;
    if (testFailure()) passed++;      // টেস্ট ২ রান করলাম, পাস হলে কাউন্টার ১ বাড়বে

    // টেস্টের ফাইনাল রেজাল্ট প্রিন্ট করা
    printf("Passed %d/%d tests\n", passed, total);
    
    // সব টেস্ট পাস করলে প্রোগ্রাম ০ রিটার্ন করবে (Success), নাহলে ১ (Failure)
    if (passed == total) return 0;
    return 1;
}