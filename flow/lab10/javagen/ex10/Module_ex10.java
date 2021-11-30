// HASH COLLISIONS: YES
// timestamp: 1.638268265E12

package ex10;

import com.area9innovation.flow.*;

@SuppressWarnings("unchecked")
final class Module_ex10 {
	public static String g_ZERO_DIV;
	public static void init() {
		g_ZERO_DIV="Divison by zero";
	}
	public static final Struct_RatFunc f_ar2ArRat(Struct aexpr) {
			Struct l0__tmp = aexpr;
			switch (l0__tmp.getTypeId()) {
			case 15/*ArVar*/: {
				final Struct_ArVar l1__tmp = (Struct_ArVar)l0__tmp;
				final String l2_variable = l1__tmp.f_name;
				final String l3_variable = l1__tmp.f_name;
				return (new Struct_RatFunc((new Struct_Polinome(Module_tree.f_makeTree1((new Struct_Monome(Module_tree.f_makeTree1(l3_variable, 1))), 1))), (new Struct_Polinome(Module_tree.f_makeTree1((new Struct_Monome(Module_tree.f_makeTree())), 1)))));
			}
			case 9/*ArInt*/: {
				final Struct_ArInt l1__tmp = (Struct_ArInt)l0__tmp;
				final int l4_val = l1__tmp.f_val;
				final int l5_val = l1__tmp.f_val;
				return (new Struct_RatFunc((new Struct_Polinome(Module_tree.f_makeTree1((new Struct_Monome(Module_tree.f_makeTree())), l5_val))), (new Struct_Polinome(Module_tree.f_makeTree1((new Struct_Monome(Module_tree.f_makeTree())), 1)))));
			}
			case 14/*ArSum*/: {
				final Struct_ArSum l1__tmp = (Struct_ArSum)l0__tmp;
				final Struct l6_lhs = l1__tmp.f_lhs;
				final Struct l7_rhs = l1__tmp.f_rhs;
				final Struct l8_lhs = l1__tmp.f_lhs;
				final Struct l9_rhs = l1__tmp.f_rhs;
				final Struct_RatFunc l10_left = Module_ex10.f_ar2ArRat(l8_lhs);
				final Struct_RatFunc l11_right = Module_ex10.f_ar2ArRat(l9_rhs);
				return (new Struct_RatFunc(Module_ex10.f_sumPolinomes(Module_ex10.f_multPolinomes(l10_left.f_num, l11_right.f_denum), Module_ex10.f_multPolinomes(l11_right.f_num, l10_left.f_denum)), Module_ex10.f_multPolinomes(l10_left.f_denum, l11_right.f_denum)));
			}
			case 13/*ArSub*/: {
				final Struct_ArSub l1__tmp = (Struct_ArSub)l0__tmp;
				final Struct l12_lhs = l1__tmp.f_lhs;
				final Struct l13_rhs = l1__tmp.f_rhs;
				final Struct l14_lhs = l1__tmp.f_lhs;
				final Struct l15_rhs = l1__tmp.f_rhs;
				final Struct_RatFunc l16_left = Module_ex10.f_ar2ArRat(l14_lhs);
				final Struct_RatFunc l17_right = Module_ex10.f_invRat(Module_ex10.f_ar2ArRat(l15_rhs));
				return (new Struct_RatFunc(Module_ex10.f_sumPolinomes(Module_ex10.f_multPolinomes(l16_left.f_num, l17_right.f_denum), Module_ex10.f_multPolinomes(l17_right.f_num, l16_left.f_denum)), Module_ex10.f_multPolinomes(l16_left.f_denum, l17_right.f_denum)));
			}
			case 11/*ArMult*/: {
				final Struct_ArMult l1__tmp = (Struct_ArMult)l0__tmp;
				final Struct l18_lhs = l1__tmp.f_lhs;
				final Struct l19_rhs = l1__tmp.f_rhs;
				final Struct l20_lhs = l1__tmp.f_lhs;
				final Struct l21_rhs = l1__tmp.f_rhs;
				final Struct_RatFunc l22_left = Module_ex10.f_ar2ArRat(l20_lhs);
				final Struct_RatFunc l23_right = Module_ex10.f_invRat(Module_ex10.f_ar2ArRat(l21_rhs));
				return (new Struct_RatFunc(Module_ex10.f_multPolinomes(l22_left.f_num, l23_right.f_num), Module_ex10.f_multPolinomes(l22_left.f_denum, l23_right.f_denum)));
			}
			case 8/*ArDiv*/: {
				final Struct_ArDiv l1__tmp = (Struct_ArDiv)l0__tmp;
				final Struct l24_lhs = l1__tmp.f_lhs;
				final Struct l25_rhs = l1__tmp.f_rhs;
				final Struct l26_lhs = l1__tmp.f_lhs;
				final Struct l27_rhs = l1__tmp.f_rhs;
				final Struct_RatFunc l28_left = Module_ex10.f_ar2ArRat(l26_lhs);
				final Struct_RatFunc l29_right = Module_ex10.f_invRat(Module_ex10.f_ar2ArRat(l27_rhs));
				return (new Struct_RatFunc(Module_ex10.f_multPolinomes(l28_left.f_num, l29_right.f_denum), Module_ex10.f_multPolinomes(l28_left.f_denum, l29_right.f_num)));
			}
			case 10/*ArInv*/: {
				final Struct_ArInv l1__tmp = (Struct_ArInv)l0__tmp;
				final Struct l30_income = l1__tmp.f_arg;
				final Struct l31_income = l1__tmp.f_arg;
				final Struct_RatFunc l32_in = Module_ex10.f_ar2ArRat(l31_income);
				return Module_ex10.f_invRat(l32_in);
			}
			case 12/*ArRat*/: {
				final Struct_ArRat l1__tmp = (Struct_ArRat)l0__tmp;
				final int l33_num = l1__tmp.f_num;
				final int l34_denum = l1__tmp.f_denum;
				final int l35_num = l1__tmp.f_num;
				final int l36_denum = l1__tmp.f_denum;
				return (new Struct_RatFunc((new Struct_Polinome(Module_tree.f_makeTree1((new Struct_Monome(Module_tree.f_makeTree())), l35_num))), (new Struct_Polinome(Module_tree.f_makeTree1((new Struct_Monome(Module_tree.f_makeTree())), l36_denum)))));
			}
			default:
				throw new RuntimeException("Unexpected struct in switch: "+l0__tmp.getTypeName());
			}
		}
	public static final Struct_RatFunc f_invRat(Struct_RatFunc afunc) {
			final Struct l2_$1 = afunc.f_num.f_monomes;
			final Func1<Integer,Integer> l3_$0 = (Func1<Integer, Integer>)(Integer amonome) -> {
				return ((Integer)(-((int)amonome)));
			};
			return (new Struct_RatFunc((new Struct_Polinome(Module_tree.f_mapTree(l2_$1, ((Func1<Object,Object>)(Func1)l3_$0)))), afunc.f_denum));
		}
	public static final Object f_main() {
			final String l0_s = "((((9 * (x * x)) - 4) / ((3 * x) + 2)) - (3 * x))";
			final Struct l1_tree = Module_ex10.f_s2ar(l0_s);
			Module_runtime.f_println(Module_ex10.f_ratFunc2s(Module_ex10.f_ar2ArRat(l1_tree)));
			return Module_runtime.f_println(Module_ex10.f_simplify(Module_ex10.f_ratFunc2arExpr(Module_ex10.f_ar2ArRat(l1_tree))));
		}
	public static final Struct f_monome2arExpr(Struct_Monome amonome) {
			final Struct l3_$1 = amonome.f_monome;
			final Struct_ArInt l4_$2 = (new Struct_ArInt(1));
			final Func3<Struct_ArInt,String, Integer, Struct_ArInt> l5_$0 = (Func3<Struct_ArInt, String, Integer, Struct_ArInt>)(String avar, Integer apow_0, Struct_ArInt aacc) -> {
				return (new Struct_ArInt(0));
			};
			Module_tree.f_foldTree(l3_$1, l4_$2, ((Func3<Object,Object, Object, Object>)(Func3)l5_$0));
			return (new Struct_ArRat(1, 2));
		}
	public static final String f_monome2s(Struct_Monome amonome, int acoef) {
			if ((acoef==0)) {
				return "";
			} else {
				if ((acoef==1)) {
					if (Module_tree.f_isEmptyTree(amonome.f_monome)) {
						return "1";
					} else {
						final Struct l2_$1 = amonome.f_monome;
						final Func3<String,String, Integer, String> l3_$0 = (Func3<String, String, Integer, String>)(String amon, Integer apow_0, String ares) -> {
							if ((((int)apow_0)==1)) {
								return Module_string.f_concatStrings((new Object[] { ares, amon }));
							} else {
								return Module_string.f_concatStrings((new Object[] { ares, amon, "^", "(", Module_string.f_i2s(((int)apow_0)), ")" }));
							}
						};
						return ((String)Module_tree.f_foldRTree(l2_$1, "", ((Func3<Object,Object, Object, Object>)(Func3)l3_$0)));
					}
				} else {
					final Struct l7_$5 = amonome.f_monome;
					final String l8_$6 = Module_string.f_i2s(acoef);
					final Func3<String,String, Integer, String> l9_$4 = (Func3<String, String, Integer, String>)(String amon, Integer apow_0, String ares) -> {
						if ((((int)apow_0)==1)) {
							return Module_string.f_concatStrings((new Object[] { ares, amon }));
						} else {
							return Module_string.f_concatStrings((new Object[] { ares, amon, "^", "(", Module_string.f_i2s(((int)apow_0)), ")" }));
						}
					};
					return ((String)Module_tree.f_foldRTree(l7_$5, l8_$6, ((Func3<Object,Object, Object, Object>)(Func3)l9_$4)));
				}
			}
		}
	public static final Struct_Polinome f_multPolinomes(Struct_Polinome aleft, Struct_Polinome aright) {
			final Struct l3_$1 = aleft.f_monomes;
			final Struct l4_$2 = Module_tree.f_makeTree();
			final Struct_Polinome l6_right = aright;
			final Func3<Struct,Struct_Monome, Integer, Struct> l5_$0 = (Func3<Struct, Struct_Monome, Integer, Struct>)(Struct_Monome aleft_monome, Integer aleft_coef, Struct aleft_acc) -> {
				final Struct l8_$7 = l6_right.f_monomes;
				final Func3<Struct,Struct_Monome, Integer, Struct> l9_$6 = (Func3<Struct, Struct_Monome, Integer, Struct>)(Struct_Monome aright_monome, Integer aright_coef, Struct aright_acc) -> {
					final Struct l13_$11 = aleft_monome.f_monome;
					final Struct l14_$12 = aright_monome.f_monome;
					final Func3<Integer,String, Integer, Integer> l15_$10 = (Func3<Integer, String, Integer, Integer>)(String ak, Integer al, Integer ar) -> {
						return ((Integer)(((int)al)+((int)ar)));
					};
					final Struct_Monome l16_monome = (new Struct_Monome(Module_tree.f_mergeTreeCustom(l13_$11, l14_$12, ((Func3<Object,Object, Object, Object>)(Func3)l15_$10))));
					final Struct l17_res = Module_tree.f_lookupTree(aright_acc, l16_monome);
					Struct l18__tmp = l17_res;
					switch (l18__tmp.getTypeId()) {
					case 108/*Some*/: {
						final Struct_Some l19__tmp = (Struct_Some)l18__tmp;
						final Object l20__value_ = l19__tmp.f_value;
						final int l21__value_ = ((int)l19__tmp.f_value);
						return Module_tree.f_setTree(aright_acc, l16_monome, (l21__value_+(((int)aright_coef)*((int)aleft_coef))));
					}
					case 45/*None*/: {
						return Module_tree.f_setTree(aright_acc, l16_monome, (((int)aright_coef)*((int)aleft_coef)));
					}
					default:
						throw new RuntimeException("Unexpected struct in switch: "+l18__tmp.getTypeName());
					}
				};
				return ((Struct)Module_tree.f_foldTree(l8_$7, aleft_acc, ((Func3<Object,Object, Object, Object>)(Func3)l9_$6)));
			};
			return (new Struct_Polinome(((Struct)Module_tree.f_foldTree(l3_$1, l4_$2, ((Func3<Object,Object, Object, Object>)(Func3)l5_$0)))));
		}
	public static final Struct f_polinome2arExpr(Struct_Polinome apolinome) {
			final Struct l3_$1 = apolinome.f_monomes;
			final Struct_ArInt l4_$2 = (new Struct_ArInt(0));
			final Func3<Struct_ArInt,Struct_Monome, Integer, Struct_ArInt> l5_$0 = (Func3<Struct_ArInt, Struct_Monome, Integer, Struct_ArInt>)(Struct_Monome amonome, Integer acoef, Struct_ArInt aacc) -> {
				Module_ex10.f_monome2arExpr(amonome);
				Module_runtime.f_println(acoef);
				return (new Struct_ArInt(0));
			};
			Module_tree.f_foldTree(l3_$1, l4_$2, ((Func3<Object,Object, Object, Object>)(Func3)l5_$0));
			Module_runtime.f_println("");
			return (new Struct_ArRat(1, 2));
		}
	public static final String f_polinome2s(Struct_Polinome apolinome) {
			final Struct l2_$1 = apolinome.f_monomes;
			final Func3<String,Struct_Monome, Integer, String> l3_$0 = (Func3<String, Struct_Monome, Integer, String>)(Struct_Monome amonomes, Integer acoef, String ares) -> {
				if ((ares).equals("")) {
					if ((((int)acoef)>=0)) {
						return Module_ex10.f_monome2s(amonomes, ((int)acoef));
					} else {
						return Module_string.f_concatStrings((new Object[] { "-", Module_ex10.f_monome2s(amonomes, Module_math.f_iabs(((int)acoef))) }));
					}
				} else {
					final String l4_monome_str = Module_ex10.f_monome2s(amonomes, ((int)acoef));
					if ((!(l4_monome_str).equals(""))) {
						if ((((int)acoef)>=0)) {
							return Module_string.f_concatStrings((new Object[] { ares, " + ", Module_ex10.f_monome2s(amonomes, ((int)acoef)) }));
						} else {
							return Module_string.f_concatStrings((new Object[] { ares, " - ", Module_ex10.f_monome2s(amonomes, Module_math.f_iabs(((int)acoef))) }));
						}
					} else {
						return Module_string.f_concatStrings((new Object[] { ares, Module_ex10.f_monome2s(amonomes, ((int)acoef)) }));
					}
				}
			};
			return ((String)Module_tree.f_foldRTree(l2_$1, "", ((Func3<Object,Object, Object, Object>)(Func3)l3_$0)));
		}
	public static final Struct f_ratFunc2arExpr(Struct_RatFunc afunc) {
			return (new Struct_ArDiv(Module_ex10.f_polinome2arExpr(afunc.f_num), Module_ex10.f_polinome2arExpr(afunc.f_denum)));
		}
	public static final String f_ratFunc2s(Struct_RatFunc afunc) {
			final String l0_left = Module_ex10.f_polinome2s(afunc.f_num);
			final String l1_right = Module_ex10.f_polinome2s(afunc.f_denum);
			if ((l1_right).equals("")) {
				return Module_ex10.g_ZERO_DIV;
			} else {
				if ((l0_left).equals("")) {
					return "0";
				} else {
					if ((l1_right).equals("1")) {
						return l0_left;
					} else {
						if ((l1_right).equals("-1")) {
							final Struct_RatFunc l2_func_inv = Module_ex10.f_invRat(afunc);
							return Module_ex10.f_polinome2s(l2_func_inv.f_num);
						} else {
							return Module_string.f_concatStrings((new Object[] { "(", l0_left, ")", " / ", "(", l1_right, ")" }));
						}
					}
				}
			}
		}
	public static final Struct f_s2ar(String astr) {
			final String l0_e_gr = "S = int | rat | inv | sum | sub | mul | div | var;\nsum = \"(\" ws S:l ws \"+\" ws S:r ws \")\" {ArSum(:l, :r)};\nsub = \"(\" ws S:l ws \"-\" ws S:r ws \")\" {ArSub(:l, :r)};\nmul = \"(\" ws S:l ws \"*\" ws S:r ws \")\" {ArMult(:l, :r)};\ndiv = \"(\" ws S:l ws \"/\" ws S:r ws \")\" {ArDiv(:l, :r)};\nrat = \"(\" ws int$n ws \"/\" ws int$d ws \")\" {ArRat(s2i($n), s2i($d))};\nvar = character+ $s {ArVar(:s)};\ninv = \"-\" ws S:a {ArInv(:a)};\nint = digit+ $s {ArInt(s2i($s))};\ndigit = '0'-'9';\ncharacter = 'a'-'z' | 'A'-'Z';\nws = (' ' | '\\t' | '\\n' | '\\r')*;";
			final Object[] l4_$3 = Module_driver.f_compilePegGrammar(l0_e_gr);
			final Struct l5_$2 = Module_pegaction.g_defaultPegActions.f_t;
			final Func1<Struct_ArInt,Object[]> l6_$1 = (Func1<Struct_ArInt, Object[]>)(Object[] as) -> {
				return (new Struct_ArInt(Module_math.f_s2i(((String)(as[0])))));
			};
			return ((Struct)Module_parsic.f_parsic(l4_$3, astr, (new Struct_SemanticActions(Module_tree.f_setTree(l5_$2, "createArInt", l6_$1)))));
		}
	public static final Struct f_simplify(Struct aexpr) {
			Struct l0__tmp = aexpr;
			switch (l0__tmp.getTypeId()) {
			case 15/*ArVar*/: {
				final Struct_ArVar l1__tmp = (Struct_ArVar)l0__tmp;
				final String l2_variable = l1__tmp.f_name;
				final String l3_variable = l1__tmp.f_name;
				return (new Struct_ArVar(l3_variable));
			}
			case 9/*ArInt*/: {
				final Struct_ArInt l1__tmp = (Struct_ArInt)l0__tmp;
				final int l4_val = l1__tmp.f_val;
				final int l5_val = l1__tmp.f_val;
				return (new Struct_ArRat(l5_val, 1));
			}
			case 14/*ArSum*/: {
				final Struct_ArSum l1__tmp = (Struct_ArSum)l0__tmp;
				final Struct l6_lefths = l1__tmp.f_lhs;
				final Struct l7_righths = l1__tmp.f_rhs;
				final Struct l8_lefths = l1__tmp.f_lhs;
				final Struct l9_righths = l1__tmp.f_rhs;
				final Struct l10_lhs = Module_ex10.f_simplify(l8_lefths);
				final Struct l11_rhs = Module_ex10.f_simplify(l9_righths);
				Struct l12__tmp = l10_lhs;
				switch (l12__tmp.getTypeId()) {
				case 12/*ArRat*/: {
					final Struct_ArRat l13__tmp = (Struct_ArRat)l12__tmp;
					final int l14_lnum = l13__tmp.f_num;
					final int l15_ldenum = l13__tmp.f_denum;
					final int l16_lnum = l13__tmp.f_num;
					final int l17_ldenum = l13__tmp.f_denum;
					Struct l18__tmp = l11_rhs;
					switch (l18__tmp.getTypeId()) {
					case 12/*ArRat*/: {
						final Struct_ArRat l19__tmp = (Struct_ArRat)l18__tmp;
						final int l20_rnum = l19__tmp.f_num;
						final int l21_rdenum = l19__tmp.f_denum;
						final int l22_rnum = l19__tmp.f_num;
						final int l23_rdenum = l19__tmp.f_denum;
						if ((l16_lnum==0)) {
							return l19__tmp;
						} else {
							if ((l22_rnum==0)) {
								return l13__tmp;
							} else {
								return (new Struct_ArSum(l13__tmp, l19__tmp));
							}
						}
					}
					default: {
						if ((l16_lnum==0)) {
							return l11_rhs;
						} else {
							return (new Struct_ArSum(l13__tmp, l11_rhs));
						}
					}
					}
				}
				default: {
					Struct l24__tmp = l11_rhs;
					switch (l24__tmp.getTypeId()) {
					case 12/*ArRat*/: {
						final Struct_ArRat l25__tmp = (Struct_ArRat)l24__tmp;
						final int l26_rnum = l25__tmp.f_num;
						final int l27_rdenum = l25__tmp.f_denum;
						final int l28_rnum = l25__tmp.f_num;
						final int l29_rdenum = l25__tmp.f_denum;
						if ((l28_rnum==0)) {
							return l10_lhs;
						} else {
							return (new Struct_ArSum(l10_lhs, l25__tmp));
						}
					}
					default: {
						return (new Struct_ArSum(l10_lhs, l11_rhs));
					}
					}
				}
				}
			}
			case 13/*ArSub*/: {
				final Struct_ArSub l1__tmp = (Struct_ArSub)l0__tmp;
				final Struct l30_lefths = l1__tmp.f_lhs;
				final Struct l31_righths = l1__tmp.f_rhs;
				final Struct l32_lefths = l1__tmp.f_lhs;
				final Struct l33_righths = l1__tmp.f_rhs;
				final Struct l34_lhs = Module_ex10.f_simplify(l32_lefths);
				final Struct l35_rhs = Module_ex10.f_simplify(l33_righths);
				Struct l36__tmp = l34_lhs;
				switch (l36__tmp.getTypeId()) {
				case 12/*ArRat*/: {
					final Struct_ArRat l37__tmp = (Struct_ArRat)l36__tmp;
					final int l38_lnum = l37__tmp.f_num;
					final int l39_ldenum = l37__tmp.f_denum;
					final int l40_lnum = l37__tmp.f_num;
					final int l41_ldenum = l37__tmp.f_denum;
					Struct l42__tmp = l35_rhs;
					switch (l42__tmp.getTypeId()) {
					case 12/*ArRat*/: {
						final Struct_ArRat l43__tmp = (Struct_ArRat)l42__tmp;
						final int l44_rnum = l43__tmp.f_num;
						final int l45_rdenum = l43__tmp.f_denum;
						final int l46_rnum = l43__tmp.f_num;
						final int l47_rdenum = l43__tmp.f_denum;
						if ((l40_lnum==0)) {
							return (new Struct_ArInv(l43__tmp));
						} else {
							if ((l46_rnum==0)) {
								return l37__tmp;
							} else {
								return (new Struct_ArSub(l37__tmp, l43__tmp));
							}
						}
					}
					default: {
						if ((l40_lnum==0)) {
							return (new Struct_ArInv(l35_rhs));
						} else {
							return (new Struct_ArSub(l37__tmp, l35_rhs));
						}
					}
					}
				}
				default: {
					Struct l48__tmp = l35_rhs;
					switch (l48__tmp.getTypeId()) {
					case 12/*ArRat*/: {
						final Struct_ArRat l49__tmp = (Struct_ArRat)l48__tmp;
						final int l50_rnum = l49__tmp.f_num;
						final int l51_rdenum = l49__tmp.f_denum;
						final int l52_rnum = l49__tmp.f_num;
						final int l53_rdenum = l49__tmp.f_denum;
						if ((l52_rnum==0)) {
							return l34_lhs;
						} else {
							return (new Struct_ArSub(l34_lhs, l49__tmp));
						}
					}
					default: {
						return (new Struct_ArSub(l34_lhs, l35_rhs));
					}
					}
				}
				}
			}
			case 11/*ArMult*/: {
				final Struct_ArMult l1__tmp = (Struct_ArMult)l0__tmp;
				final Struct l54_lefths = l1__tmp.f_lhs;
				final Struct l55_righths = l1__tmp.f_rhs;
				final Struct l56_lefths = l1__tmp.f_lhs;
				final Struct l57_righths = l1__tmp.f_rhs;
				final Struct l58_lhs = Module_ex10.f_simplify(l56_lefths);
				final Struct l59_rhs = Module_ex10.f_simplify(l57_righths);
				Struct l60__tmp = l58_lhs;
				switch (l60__tmp.getTypeId()) {
				case 12/*ArRat*/: {
					final Struct_ArRat l61__tmp = (Struct_ArRat)l60__tmp;
					final int l62_lnum = l61__tmp.f_num;
					final int l63_ldenum = l61__tmp.f_denum;
					final int l64_lnum = l61__tmp.f_num;
					final int l65_ldenum = l61__tmp.f_denum;
					Struct l66__tmp = l59_rhs;
					switch (l66__tmp.getTypeId()) {
					case 12/*ArRat*/: {
						final Struct_ArRat l67__tmp = (Struct_ArRat)l66__tmp;
						final int l68_rnum = l67__tmp.f_num;
						final int l69_rdenum = l67__tmp.f_denum;
						final int l70_rnum = l67__tmp.f_num;
						final int l71_rdenum = l67__tmp.f_denum;
						if (((l64_lnum==0)||(l70_rnum==0))) {
							return (new Struct_ArRat(0, 1));
						} else {
							if (((l64_lnum==1)&&(l65_ldenum==1))) {
								return l67__tmp;
							} else {
								if (((l70_rnum==1)&&(l71_rdenum==1))) {
									return l61__tmp;
								} else {
									return (new Struct_ArMult(l61__tmp, l67__tmp));
								}
							}
						}
					}
					default: {
						if ((l64_lnum==0)) {
							return (new Struct_ArRat(0, 1));
						} else {
							return (new Struct_ArMult(l61__tmp, l59_rhs));
						}
					}
					}
				}
				default: {
					Struct l72__tmp = l59_rhs;
					switch (l72__tmp.getTypeId()) {
					case 12/*ArRat*/: {
						final Struct_ArRat l73__tmp = (Struct_ArRat)l72__tmp;
						final int l74_rnum = l73__tmp.f_num;
						final int l75_rdenum = l73__tmp.f_denum;
						final int l76_rnum = l73__tmp.f_num;
						final int l77_rdenum = l73__tmp.f_denum;
						if ((l76_rnum==0)) {
							return (new Struct_ArRat(0, 1));
						} else {
							return (new Struct_ArMult(l58_lhs, l73__tmp));
						}
					}
					default: {
						return (new Struct_ArMult(l58_lhs, l59_rhs));
					}
					}
				}
				}
			}
			case 8/*ArDiv*/: {
				final Struct_ArDiv l1__tmp = (Struct_ArDiv)l0__tmp;
				final Struct l78_lefths = l1__tmp.f_lhs;
				final Struct l79_righths = l1__tmp.f_rhs;
				final Struct l80_lefths = l1__tmp.f_lhs;
				final Struct l81_righths = l1__tmp.f_rhs;
				final Struct l82_lhs = Module_ex10.f_simplify(l80_lefths);
				final Struct l83_rhs = Module_ex10.f_simplify(l81_righths);
				Struct l84__tmp = l82_lhs;
				switch (l84__tmp.getTypeId()) {
				case 12/*ArRat*/: {
					final Struct_ArRat l85__tmp = (Struct_ArRat)l84__tmp;
					final int l86_lnum = l85__tmp.f_num;
					final int l87_ldenum = l85__tmp.f_denum;
					final int l88_lnum = l85__tmp.f_num;
					final int l89_ldenum = l85__tmp.f_denum;
					Struct l90__tmp = l83_rhs;
					switch (l90__tmp.getTypeId()) {
					case 12/*ArRat*/: {
						final Struct_ArRat l91__tmp = (Struct_ArRat)l90__tmp;
						final int l92_rnum = l91__tmp.f_num;
						final int l93_rdenum = l91__tmp.f_denum;
						final int l94_rnum = l91__tmp.f_num;
						final int l95_rdenum = l91__tmp.f_denum;
						if ((l88_lnum==0)) {
							return (new Struct_ArRat(0, 1));
						} else {
							return (new Struct_ArDiv(l85__tmp, l91__tmp));
						}
					}
					default: {
						return (new Struct_ArDiv(l85__tmp, l83_rhs));
					}
					}
				}
				default: {
					return (new Struct_ArDiv(l82_lhs, l83_rhs));
				}
				}
			}
			case 10/*ArInv*/: {
				final Struct_ArInv l1__tmp = (Struct_ArInv)l0__tmp;
				final Struct l96_income = l1__tmp.f_arg;
				final Struct l97_income = l1__tmp.f_arg;
				return (new Struct_ArInv(l97_income));
			}
			case 12/*ArRat*/: {
				final Struct_ArRat l1__tmp = (Struct_ArRat)l0__tmp;
				final int l98_num = l1__tmp.f_num;
				final int l99_denum = l1__tmp.f_denum;
				final int l100_num = l1__tmp.f_num;
				final int l101_denum = l1__tmp.f_denum;
				final int l102_gcd_0 = Module_math.f_iabs(Module_math.f_gcd(l100_num, l101_denum));
				return (new Struct_ArRat((l100_num/l102_gcd_0), (l101_denum/l102_gcd_0)));
			}
			default:
				throw new RuntimeException("Unexpected struct in switch: "+l0__tmp.getTypeName());
			}
		}
	public static final Struct_Polinome f_sumPolinomes(Struct_Polinome aleft, Struct_Polinome aright) {
			final Struct l3_$1 = aleft.f_monomes;
			final Struct l4_$2 = aright.f_monomes;
			final Func3<Integer,Struct_Monome, Integer, Integer> l5_$0 = (Func3<Integer, Struct_Monome, Integer, Integer>)(Struct_Monome ak, Integer aleft_coef, Integer aright_coef) -> {
				return ((Integer)(((int)aright_coef)+((int)aleft_coef)));
			};
			return (new Struct_Polinome(Module_tree.f_mergeTreeCustom(l3_$1, l4_$2, ((Func3<Object,Object, Object, Object>)(Func3)l5_$0))));
		}
}
