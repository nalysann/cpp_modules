// ************************************************************************** //
//                                                                            //
//                Account.class.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#ifndef ACCOUNT_CLASS_HPP
#define ACCOUNT_CLASS_HPP

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {
  public:
    typedef Account t;

    static int getNbAccounts();
    static int getTotalAmount();
    static int getNbDeposits();
    static int getNbWithdrawals();
    static int getNbCheckAmountCalls();
    static void displayAccountsInfos();

    explicit Account(int initial_deposit = 0);
    ~Account();

    void makeDeposit(int deposit);
    bool makeWithdrawal(int withdrawal);
    int checkAmount() const;
    void displayStatus() const;

  private:
    static int _nbAccounts;
    static int _totalAmount;
    static int _totalNbDeposits;
    static int _totalNbWithdrawals;
    static int _totalCheckAmountCalls;

    static void _displayTimestamp();

    int _accountIndex;
    int _amount;
    int _nbDeposits;
    int _nbWithdrawals;
};

#endif



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// My boss is a dick                                                          //
// ************************************************************************** //
