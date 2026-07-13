#ifndef CAPTCHA_H   // যদি CAPTCHA_H আগে ডিফাইন করা না থাকে
#define CAPTCHA_H   // তবে এখানে CAPTCHA_H ডিফাইন করো (যাতে ডুপ্লিকেট ইনক্লুড না হয়)

#define CAPTCHA_LENGTH 5 // ক্যাপচা কোডটি কত অক্ষরের হবে তা ডিফাইন করলাম (৫ অক্ষরের)

//  র্যান্ডম ক্যাপচা জেনারেট করার জন্য ফাংশন প্রোটোটাইপ
void generateCaptcha(char *captcha);

// ইউজারের ইনপুট ভেরিফাই করার জন্য ফাংশন প্রোটোটাইপ (const দেওয়া হয়েছে যাতে মূল ডেটা চেঞ্জ না হয়)
int verifyCaptcha(const char *secret, const char *user_input);

#endif // CAPTCHA_H এর শেষ