/* generated by MKexpanded.sh */
#define NEED_NCURSES_CH_T 1
#include <curses.priv.h>

#ifndef CUR
#define CUR SP_TERMTYPE
#endif

#if NCURSES_EXPANDED
 void
_nc_toggle_attr_on (attr_t *S, attr_t at)
{
 { if (((int)((((unsigned long)(at) & ((chtype)((((1U) << 8) - 1U)) << ((0) + 8))) >> 8))) > 0) { (*S) = ((*S) & ALL_BUT_COLOR) | (attr_t) (at); } else { (*S) |= (attr_t) (at); } ;};
}

 void
_nc_toggle_attr_off (attr_t *S, attr_t at)
{
 { if (((int)((((unsigned long)(at) & ((chtype)((((1U) << 8) - 1U)) << ((0) + 8))) >> 8))) > 0) { (*S) &= ~(at|((chtype)((((1U) << 8) - 1U)) << ((0) + 8))); } else { (*S) &= ~(at); } ;};
}

 int
_nc_DelCharCost_sp (SCREEN *sp, int count)
{
 return (((cur_term)->type2. Strings[105] != 0) ? sp->_dch_cost : (((cur_term)->type2. Strings[21] != 0) ? (sp->_dch1_cost * count) : 1000000));
}

 int
_nc_InsCharCost_sp (SCREEN *sp, int count)
{
 return (((cur_term)->type2. Strings[108] != 0) ? sp->_ich_cost : (((cur_term)->type2. Strings[31] && (cur_term)->type2. Strings[42]) ? sp->_smir_cost + sp->_rmir_cost + (sp->_ip_cost * count) : (((cur_term)->type2. Strings[52] != 0) ? ((sp->_ich1_cost + sp->_ip_cost) * count) : 1000000)));
}

 void
_nc_UpdateAttrs_sp (SCREEN *sp, const cchar_t * c)
{
 if (!((((*((sp)->_current_attr))).attr) == (((*c)).attr) && ((((*((sp)->_current_attr))).ext_color) ? (((*((sp)->_current_attr))).ext_color) : ((int)((((unsigned long)((((*((sp)->_current_attr))).attr)) & ((chtype)((((1U) << 8) - 1U)) << ((0) + 8))) >> 8)))) == ((((*c)).ext_color) ? (((*c)).ext_color) : ((int)((((unsigned long)((((*c)).attr)) & ((chtype)((((1U) << 8) - 1U)) << ((0) + 8))) >> 8)))))) { vid_puts_sp(sp, (((*c)).attr), (short) ((((*c)).ext_color) ? (((*c)).ext_color) : ((int)((((unsigned long)((((*c)).attr)) & ((chtype)((((1U) << 8) - 1U)) << ((0) + 8))) >> 8)))), 0, _nc_outch_sp); };
}

#if NCURSES_SP_FUNCS
 int
_nc_DelCharCost (int count)
{
 return _nc_DelCharCost_sp (SP, count);
}

 int
_nc_InsCharCost (int count)
{
 return _nc_InsCharCost_sp(SP, count);
}

 void
_nc_UpdateAttrs (const cchar_t * c)
{
 _nc_UpdateAttrs_sp(SP,c);
}
#endif
#else /* ! NCURSES_EXPANDED */
NCURSES_EXPORT(void) _nc_expanded (void) { }
#endif /* NCURSES_EXPANDED */
