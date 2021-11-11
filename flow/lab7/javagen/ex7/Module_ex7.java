// HASH COLLISIONS: YES
// timestamp: 1.636517109E12

package ex7;

import com.area9innovation.flow.*;

@SuppressWarnings("unchecked")
final class Module_ex7 {
	public static String g_INVALID_INPUT;
	public static String g_ZERO_DIV;
	public static void init() {
		g_INVALID_INPUT="Invalid input";
		g_ZERO_DIV="Divison by zero";
	}
	public static final Struct f_ar2s(Struct aexpr) {
			Struct l0__tmp = aexpr;
			switch (l0__tmp.getTypeId()) {
			case 9/*ArInt*/: {
				final Struct_ArInt l1__tmp = (Struct_ArInt)l0__tmp;
				final int l2_val = l1__tmp.f_val;
				final int l3_val = l1__tmp.f_val;
				return (new Struct_Some(Module_string.f_i2s(l3_val)));
			}
			case 14/*ArSum*/: {
				final Struct_ArSum l1__tmp = (Struct_ArSum)l0__tmp;
				final Struct l4_lhs = l1__tmp.f_lhs;
				final Struct l5_rhs = l1__tmp.f_rhs;
				final Struct l6_lhs = l1__tmp.f_lhs;
				final Struct l7_rhs = l1__tmp.f_rhs;
				final Struct l8_left = Module_ex7.f_ar2s(l6_lhs);
				final Struct l9_right = Module_ex7.f_ar2s(l7_rhs);
				String l12_$10;
				Struct l13__tmp = l8_left;
				switch (l13__tmp.getTypeId()) {
				case 105/*Some*/: {
					final Struct_Some l14__tmp = (Struct_Some)l13__tmp;
					final Object l15__value_ = l14__tmp.f_value;
					final String l16__value_ = ((String)l14__tmp.f_value);
					l12_$10=l16__value_;
					break;
				}
				case 44/*None*/: {
					l12_$10=Module_ex7.g_ZERO_DIV;
					break;
				}
				default:
					throw new RuntimeException("Unexpected struct in switch: "+l13__tmp.getTypeName());
				}
				String l17_$11;
				Struct l18__tmp = l9_right;
				switch (l18__tmp.getTypeId()) {
				case 105/*Some*/: {
					final Struct_Some l19__tmp = (Struct_Some)l18__tmp;
					final Object l20__value_ = l19__tmp.f_value;
					final String l21__value_ = ((String)l19__tmp.f_value);
					l17_$11=l21__value_;
					break;
				}
				case 44/*None*/: {
					l17_$11=Module_ex7.g_ZERO_DIV;
					break;
				}
				default:
					throw new RuntimeException("Unexpected struct in switch: "+l18__tmp.getTypeName());
				}
				final Object[] l22_str = (new Object[] { "(", l12_$10, "+", l17_$11, ")" });
				return (new Struct_Some(Module_string.f_strGlue(l22_str, "")));
			}
			case 11/*ArMult*/: {
				final Struct_ArMult l1__tmp = (Struct_ArMult)l0__tmp;
				final Struct l23_lhs = l1__tmp.f_lhs;
				final Struct l24_rhs = l1__tmp.f_rhs;
				final Struct l25_lhs = l1__tmp.f_lhs;
				final Struct l26_rhs = l1__tmp.f_rhs;
				final Struct l27_left = Module_ex7.f_ar2s(l25_lhs);
				final Struct l28_right = Module_ex7.f_ar2s(l26_rhs);
				String l31_$29;
				Struct l32__tmp = l27_left;
				switch (l32__tmp.getTypeId()) {
				case 105/*Some*/: {
					final Struct_Some l33__tmp = (Struct_Some)l32__tmp;
					final Object l34__value_ = l33__tmp.f_value;
					final String l35__value_ = ((String)l33__tmp.f_value);
					l31_$29=l35__value_;
					break;
				}
				case 44/*None*/: {
					l31_$29=Module_ex7.g_ZERO_DIV;
					break;
				}
				default:
					throw new RuntimeException("Unexpected struct in switch: "+l32__tmp.getTypeName());
				}
				String l36_$30;
				Struct l37__tmp = l28_right;
				switch (l37__tmp.getTypeId()) {
				case 105/*Some*/: {
					final Struct_Some l38__tmp = (Struct_Some)l37__tmp;
					final Object l39__value_ = l38__tmp.f_value;
					final String l40__value_ = ((String)l38__tmp.f_value);
					l36_$30=l40__value_;
					break;
				}
				case 44/*None*/: {
					l36_$30=Module_ex7.g_ZERO_DIV;
					break;
				}
				default:
					throw new RuntimeException("Unexpected struct in switch: "+l37__tmp.getTypeName());
				}
				final Object[] l41_str = (new Object[] { "(", l31_$29, "*", l36_$30, ")" });
				return (new Struct_Some(Module_string.f_strGlue(l41_str, "")));
			}
			case 13/*ArSub*/: {
				final Struct_ArSub l1__tmp = (Struct_ArSub)l0__tmp;
				final Struct l42_lhs = l1__tmp.f_lhs;
				final Struct l43_rhs = l1__tmp.f_rhs;
				final Struct l44_lhs = l1__tmp.f_lhs;
				final Struct l45_rhs = l1__tmp.f_rhs;
				final Struct l46_left = Module_ex7.f_ar2s(l44_lhs);
				final Struct l47_right = Module_ex7.f_ar2s(l45_rhs);
				String l50_$48;
				Struct l51__tmp = l46_left;
				switch (l51__tmp.getTypeId()) {
				case 105/*Some*/: {
					final Struct_Some l52__tmp = (Struct_Some)l51__tmp;
					final Object l53__value_ = l52__tmp.f_value;
					final String l54__value_ = ((String)l52__tmp.f_value);
					l50_$48=l54__value_;
					break;
				}
				case 44/*None*/: {
					l50_$48=Module_ex7.g_ZERO_DIV;
					break;
				}
				default:
					throw new RuntimeException("Unexpected struct in switch: "+l51__tmp.getTypeName());
				}
				String l55_$49;
				Struct l56__tmp = l47_right;
				switch (l56__tmp.getTypeId()) {
				case 105/*Some*/: {
					final Struct_Some l57__tmp = (Struct_Some)l56__tmp;
					final Object l58__value_ = l57__tmp.f_value;
					final String l59__value_ = ((String)l57__tmp.f_value);
					l55_$49=l59__value_;
					break;
				}
				case 44/*None*/: {
					l55_$49=Module_ex7.g_ZERO_DIV;
					break;
				}
				default:
					throw new RuntimeException("Unexpected struct in switch: "+l56__tmp.getTypeName());
				}
				final Object[] l60_str = (new Object[] { "(", l50_$48, "-", l55_$49, ")" });
				return (new Struct_Some(Module_string.f_strGlue(l60_str, "")));
			}
			case 8/*ArDiv*/: {
				final Struct_ArDiv l1__tmp = (Struct_ArDiv)l0__tmp;
				final Struct l61_lhs = l1__tmp.f_lhs;
				final Struct l62_rhs = l1__tmp.f_rhs;
				final Struct l63_lhs = l1__tmp.f_lhs;
				final Struct l64_rhs = l1__tmp.f_rhs;
				final Struct l65_left = Module_ex7.f_ar2s(l63_lhs);
				final Struct l66_right = Module_ex7.f_ar2s(l64_rhs);
				String l69_$67;
				Struct l70__tmp = l65_left;
				switch (l70__tmp.getTypeId()) {
				case 105/*Some*/: {
					final Struct_Some l71__tmp = (Struct_Some)l70__tmp;
					final Object l72__value_ = l71__tmp.f_value;
					final String l73__value_ = ((String)l71__tmp.f_value);
					l69_$67=l73__value_;
					break;
				}
				case 44/*None*/: {
					l69_$67=Module_ex7.g_ZERO_DIV;
					break;
				}
				default:
					throw new RuntimeException("Unexpected struct in switch: "+l70__tmp.getTypeName());
				}
				String l74_$68;
				Struct l75__tmp = l66_right;
				switch (l75__tmp.getTypeId()) {
				case 105/*Some*/: {
					final Struct_Some l76__tmp = (Struct_Some)l75__tmp;
					final Object l77__value_ = l76__tmp.f_value;
					final String l78__value_ = ((String)l76__tmp.f_value);
					l74_$68=l78__value_;
					break;
				}
				case 44/*None*/: {
					l74_$68=Module_ex7.g_ZERO_DIV;
					break;
				}
				default:
					throw new RuntimeException("Unexpected struct in switch: "+l75__tmp.getTypeName());
				}
				final Object[] l79_str = (new Object[] { "(", l69_$67, "/", l74_$68, ")" });
				return (new Struct_Some(Module_string.f_strGlue(l79_str, "")));
			}
			case 10/*ArInv*/: {
				final Struct_ArInv l1__tmp = (Struct_ArInv)l0__tmp;
				final Struct l80_value = l1__tmp.f_arg;
				final Struct l81_value = l1__tmp.f_arg;
				final Struct l82_res = Module_ex7.f_ar2s(l81_value);
				String l84_$83;
				Struct l85__tmp = l82_res;
				switch (l85__tmp.getTypeId()) {
				case 105/*Some*/: {
					final Struct_Some l86__tmp = (Struct_Some)l85__tmp;
					final Object l87__value_ = l86__tmp.f_value;
					final String l88__value_ = ((String)l86__tmp.f_value);
					l84_$83=l88__value_;
					break;
				}
				case 44/*None*/: {
					l84_$83=Module_ex7.g_ZERO_DIV;
					break;
				}
				default:
					throw new RuntimeException("Unexpected struct in switch: "+l85__tmp.getTypeName());
				}
				return (new Struct_Some(Module_string.f_strGlue((new Object[] { "-", l84_$83 }), "")));
			}
			case 12/*ArRat*/: {
				final Struct_ArRat l1__tmp = (Struct_ArRat)l0__tmp;
				final int l89_num = l1__tmp.f_num;
				final int l90_denum = l1__tmp.f_denum;
				final int l91_num = l1__tmp.f_num;
				final int l92_denum = l1__tmp.f_denum;
				if ((l92_denum==0)) {
					return ((Struct)SingletonStructs.str_None);
				} else {
					if (((l92_denum/Module_math.f_gcd(l91_num, l92_denum))==1)) {
						return (new Struct_Some(Module_string.f_i2s((l91_num/Module_math.f_gcd(l91_num, l92_denum)))));
					} else {
						final Object[] l93_str = (new Object[] { "(", Module_string.f_i2s((l91_num/Module_math.f_gcd(l91_num, l92_denum))), "/", Module_string.f_i2s((l92_denum/Module_math.f_gcd(l91_num, l92_denum))), ")" });
						return (new Struct_Some(Module_string.f_strGlue(l93_str, "")));
					}
				}
			}
			case 15/*ArVar*/: {
				final Struct_ArVar l1__tmp = (Struct_ArVar)l0__tmp;
				final String l94_variable = l1__tmp.f_name;
				final String l95_variable = l1__tmp.f_name;
				return (new Struct_Some(l95_variable));
			}
			default:
				throw new RuntimeException("Unexpected struct in switch: "+l0__tmp.getTypeName());
			}
		}
	public static final Struct f_calculate(Struct aexpr, Object[] avariables) {
			Struct l0__tmp = aexpr;
			switch (l0__tmp.getTypeId()) {
			case 15/*ArVar*/: {
				final Struct_ArVar l1__tmp = (Struct_ArVar)l0__tmp;
				final String l2_variable = l1__tmp.f_name;
				final String l3_variable = l1__tmp.f_name;
				final Struct_ArRat l4_value = Module_ex7.f_varLookup(l3_variable, avariables);
				if ((l4_value.f_denum==0)) {
					return ((Struct)SingletonStructs.str_None);
				} else {
					return (new Struct_Some(l4_value));
				}
			}
			case 9/*ArInt*/: {
				final Struct_ArInt l1__tmp = (Struct_ArInt)l0__tmp;
				final int l5_val = l1__tmp.f_val;
				final int l6_val = l1__tmp.f_val;
				return (new Struct_Some((new Struct_ArRat(l6_val, 1))));
			}
			case 14/*ArSum*/: {
				final Struct_ArSum l1__tmp = (Struct_ArSum)l0__tmp;
				final Struct l7_lhs = l1__tmp.f_lhs;
				final Struct l8_rhs = l1__tmp.f_rhs;
				final Struct l9_lhs = l1__tmp.f_lhs;
				final Struct l10_rhs = l1__tmp.f_rhs;
				final Struct l11_leftOrNone = Module_ex7.f_calculate(l9_lhs, avariables);
				final Struct l12_rightOrNone = Module_ex7.f_calculate(l10_rhs, avariables);
				if ((Module_maybe.f_isNone(l11_leftOrNone)||Module_maybe.f_isNone(l12_rightOrNone))) {
					return ((Struct)SingletonStructs.str_None);
				} else {
					Struct_ArRat l13_left;
					Struct l14__tmp = l11_leftOrNone;
					switch (l14__tmp.getTypeId()) {
					case 105/*Some*/: {
						final Struct_Some l15__tmp = (Struct_Some)l14__tmp;
						final Object l16__value_ = l15__tmp.f_value;
						final Struct_ArRat l17__value_ = ((Struct_ArRat)l15__tmp.f_value);
						l13_left=l17__value_;
						break;
					}
					case 44/*None*/: {
						l13_left=(new Struct_ArRat(0, 0));
						break;
					}
					default:
						throw new RuntimeException("Unexpected struct in switch: "+l14__tmp.getTypeName());
					}
					Struct_ArRat l18_right;
					Struct l19__tmp = l12_rightOrNone;
					switch (l19__tmp.getTypeId()) {
					case 105/*Some*/: {
						final Struct_Some l20__tmp = (Struct_Some)l19__tmp;
						final Object l21__value_ = l20__tmp.f_value;
						final Struct_ArRat l22__value_ = ((Struct_ArRat)l20__tmp.f_value);
						l18_right=l22__value_;
						break;
					}
					case 44/*None*/: {
						l18_right=(new Struct_ArRat(0, 0));
						break;
					}
					default:
						throw new RuntimeException("Unexpected struct in switch: "+l19__tmp.getTypeName());
					}
					if (((l13_left.f_denum==0)||(l18_right.f_denum==0))) {
						return ((Struct)SingletonStructs.str_None);
					} else {
						if ((l13_left.f_denum==l18_right.f_denum)) {
							return (new Struct_Some((new Struct_ArRat((l13_left.f_num+l18_right.f_num), l13_left.f_denum))));
						} else {
							final int l23_lcm_0 = Module_math.f_lcm(l13_left.f_denum, l18_right.f_denum);
							return (new Struct_Some((new Struct_ArRat(((l13_left.f_num*(l23_lcm_0/l13_left.f_denum))+(l18_right.f_num*(l23_lcm_0/l18_right.f_denum))), l23_lcm_0))));
						}
					}
				}
			}
			case 13/*ArSub*/: {
				final Struct_ArSub l1__tmp = (Struct_ArSub)l0__tmp;
				final Struct l24_lhs = l1__tmp.f_lhs;
				final Struct l25_rhs = l1__tmp.f_rhs;
				final Struct l26_lhs = l1__tmp.f_lhs;
				final Struct l27_rhs = l1__tmp.f_rhs;
				final Struct l28_leftOrNone = Module_ex7.f_calculate(l26_lhs, avariables);
				final Struct l29_rightOrNone = Module_ex7.f_calculate(l27_rhs, avariables);
				if ((Module_maybe.f_isNone(l28_leftOrNone)||Module_maybe.f_isNone(l29_rightOrNone))) {
					return ((Struct)SingletonStructs.str_None);
				} else {
					Struct_ArRat l30_left;
					Struct l31__tmp = l28_leftOrNone;
					switch (l31__tmp.getTypeId()) {
					case 105/*Some*/: {
						final Struct_Some l32__tmp = (Struct_Some)l31__tmp;
						final Object l33__value_ = l32__tmp.f_value;
						final Struct_ArRat l34__value_ = ((Struct_ArRat)l32__tmp.f_value);
						l30_left=l34__value_;
						break;
					}
					case 44/*None*/: {
						l30_left=(new Struct_ArRat(0, 0));
						break;
					}
					default:
						throw new RuntimeException("Unexpected struct in switch: "+l31__tmp.getTypeName());
					}
					Struct_ArRat l35_right;
					Struct l36__tmp = l29_rightOrNone;
					switch (l36__tmp.getTypeId()) {
					case 105/*Some*/: {
						final Struct_Some l37__tmp = (Struct_Some)l36__tmp;
						final Object l38__value_ = l37__tmp.f_value;
						final Struct_ArRat l39__value_ = ((Struct_ArRat)l37__tmp.f_value);
						l35_right=l39__value_;
						break;
					}
					case 44/*None*/: {
						l35_right=(new Struct_ArRat(0, 0));
						break;
					}
					default:
						throw new RuntimeException("Unexpected struct in switch: "+l36__tmp.getTypeName());
					}
					if (((l30_left.f_denum==0)||(l35_right.f_denum==0))) {
						return ((Struct)SingletonStructs.str_None);
					} else {
						if ((l30_left.f_denum==l35_right.f_denum)) {
							return (new Struct_Some((new Struct_ArRat((l30_left.f_num-l35_right.f_num), l30_left.f_denum))));
						} else {
							final int l40_lcm_0 = Module_math.f_lcm(l30_left.f_denum, l35_right.f_denum);
							return (new Struct_Some((new Struct_ArRat(((l30_left.f_num*(l40_lcm_0/l30_left.f_denum))-(l35_right.f_num*(l40_lcm_0/l35_right.f_denum))), l40_lcm_0))));
						}
					}
				}
			}
			case 11/*ArMult*/: {
				final Struct_ArMult l1__tmp = (Struct_ArMult)l0__tmp;
				final Struct l41_lhs = l1__tmp.f_lhs;
				final Struct l42_rhs = l1__tmp.f_rhs;
				final Struct l43_lhs = l1__tmp.f_lhs;
				final Struct l44_rhs = l1__tmp.f_rhs;
				final Struct l45_leftOrNone = Module_ex7.f_calculate(l43_lhs, avariables);
				final Struct l46_rightOrNone = Module_ex7.f_calculate(l44_rhs, avariables);
				if ((Module_maybe.f_isNone(l45_leftOrNone)||Module_maybe.f_isNone(l46_rightOrNone))) {
					return ((Struct)SingletonStructs.str_None);
				} else {
					Struct_ArRat l47_left;
					Struct l48__tmp = l45_leftOrNone;
					switch (l48__tmp.getTypeId()) {
					case 105/*Some*/: {
						final Struct_Some l49__tmp = (Struct_Some)l48__tmp;
						final Object l50__value_ = l49__tmp.f_value;
						final Struct_ArRat l51__value_ = ((Struct_ArRat)l49__tmp.f_value);
						l47_left=l51__value_;
						break;
					}
					case 44/*None*/: {
						l47_left=(new Struct_ArRat(0, 0));
						break;
					}
					default:
						throw new RuntimeException("Unexpected struct in switch: "+l48__tmp.getTypeName());
					}
					Struct_ArRat l52_right;
					Struct l53__tmp = l46_rightOrNone;
					switch (l53__tmp.getTypeId()) {
					case 105/*Some*/: {
						final Struct_Some l54__tmp = (Struct_Some)l53__tmp;
						final Object l55__value_ = l54__tmp.f_value;
						final Struct_ArRat l56__value_ = ((Struct_ArRat)l54__tmp.f_value);
						l52_right=l56__value_;
						break;
					}
					case 44/*None*/: {
						l52_right=(new Struct_ArRat(0, 0));
						break;
					}
					default:
						throw new RuntimeException("Unexpected struct in switch: "+l53__tmp.getTypeName());
					}
					if (((l47_left.f_denum==0)||(l52_right.f_denum==0))) {
						return ((Struct)SingletonStructs.str_None);
					} else {
						final int l57_gcd_0 = Module_math.f_iabs(Module_math.f_gcd((l47_left.f_num*l52_right.f_num), (l47_left.f_denum*l52_right.f_denum)));
						return (new Struct_Some((new Struct_ArRat(((l47_left.f_num*l52_right.f_num)/l57_gcd_0), ((l47_left.f_denum*l52_right.f_denum)/l57_gcd_0)))));
					}
				}
			}
			case 8/*ArDiv*/: {
				final Struct_ArDiv l1__tmp = (Struct_ArDiv)l0__tmp;
				final Struct l58_lhs = l1__tmp.f_lhs;
				final Struct l59_rhs = l1__tmp.f_rhs;
				final Struct l60_lhs = l1__tmp.f_lhs;
				final Struct l61_rhs = l1__tmp.f_rhs;
				final Struct l62_leftOrNone = Module_ex7.f_calculate(l60_lhs, avariables);
				final Struct l63_rightOrNone = Module_ex7.f_calculate(l61_rhs, avariables);
				if ((Module_maybe.f_isNone(l62_leftOrNone)||Module_maybe.f_isNone(l63_rightOrNone))) {
					return ((Struct)SingletonStructs.str_None);
				} else {
					Struct_ArRat l64_left;
					Struct l65__tmp = l62_leftOrNone;
					switch (l65__tmp.getTypeId()) {
					case 105/*Some*/: {
						final Struct_Some l66__tmp = (Struct_Some)l65__tmp;
						final Object l67__value_ = l66__tmp.f_value;
						final Struct_ArRat l68__value_ = ((Struct_ArRat)l66__tmp.f_value);
						l64_left=l68__value_;
						break;
					}
					case 44/*None*/: {
						l64_left=(new Struct_ArRat(0, 0));
						break;
					}
					default:
						throw new RuntimeException("Unexpected struct in switch: "+l65__tmp.getTypeName());
					}
					Struct_ArRat l69_right;
					Struct l70__tmp = l63_rightOrNone;
					switch (l70__tmp.getTypeId()) {
					case 105/*Some*/: {
						final Struct_Some l71__tmp = (Struct_Some)l70__tmp;
						final Object l72__value_ = l71__tmp.f_value;
						final Struct_ArRat l73__value_ = ((Struct_ArRat)l71__tmp.f_value);
						l69_right=l73__value_;
						break;
					}
					case 44/*None*/: {
						l69_right=(new Struct_ArRat(0, 0));
						break;
					}
					default:
						throw new RuntimeException("Unexpected struct in switch: "+l70__tmp.getTypeName());
					}
					if (((l64_left.f_denum==0)||(l69_right.f_denum==0))) {
						return ((Struct)SingletonStructs.str_None);
					} else {
						final int l74_gcd_0 = Module_math.f_iabs(Module_math.f_gcd((l64_left.f_num*l69_right.f_denum), (l64_left.f_denum*l69_right.f_num)));
						return (new Struct_Some((new Struct_ArRat(((l64_left.f_num*l69_right.f_denum)/l74_gcd_0), ((l64_left.f_denum*l69_right.f_num)/l74_gcd_0)))));
					}
				}
			}
			case 10/*ArInv*/: {
				final Struct_ArInv l1__tmp = (Struct_ArInv)l0__tmp;
				final Struct l75_income = l1__tmp.f_arg;
				final Struct l76_income = l1__tmp.f_arg;
				final Struct l77_valueOrNone = Module_ex7.f_calculate(l76_income, avariables);
				if (Module_maybe.f_isNone(l77_valueOrNone)) {
					return ((Struct)SingletonStructs.str_None);
				} else {
					Struct_ArRat l78_value;
					Struct l79__tmp = l77_valueOrNone;
					switch (l79__tmp.getTypeId()) {
					case 105/*Some*/: {
						final Struct_Some l80__tmp = (Struct_Some)l79__tmp;
						final Object l81__value_ = l80__tmp.f_value;
						final Struct_ArRat l82__value_ = ((Struct_ArRat)l80__tmp.f_value);
						l78_value=l82__value_;
						break;
					}
					case 44/*None*/: {
						l78_value=(new Struct_ArRat(0, 0));
						break;
					}
					default:
						throw new RuntimeException("Unexpected struct in switch: "+l79__tmp.getTypeName());
					}
					if ((l78_value.f_denum==0)) {
						return ((Struct)SingletonStructs.str_None);
					} else {
						return (new Struct_Some((new Struct_ArRat(((-1)*l78_value.f_num), l78_value.f_denum))));
					}
				}
			}
			case 12/*ArRat*/: {
				final Struct_ArRat l1__tmp = (Struct_ArRat)l0__tmp;
				final int l83_num = l1__tmp.f_num;
				final int l84_denum = l1__tmp.f_denum;
				final int l85_num = l1__tmp.f_num;
				final int l86_denum = l1__tmp.f_denum;
				return (new Struct_Some((new Struct_ArRat(l85_num, l86_denum))));
			}
			default:
				throw new RuntimeException("Unexpected struct in switch: "+l0__tmp.getTypeName());
			}
		}
	public static final Object f_main() {
			final String l0_expr = "(((3+2)*5)+2)";
			final Struct l1_ast = Module_ex7.f_s2ar(l0_expr);
			final Struct l2_resStr = Module_ex7.f_ar2s(l1_ast);
			Module_runtime.f_println(l2_resStr);
			final Object[] l3_array = SingletonStructs.arr_empty;
			Module_runtime.f_println(l2_resStr);
			return Module_ex7.f_resolve(l1_ast, l3_array);
		}
	public static final Object f_resolve(Struct aarrExpr, Object[] avariables) {
			final Struct l0_result = Module_ex7.f_calculate(aarrExpr, avariables);
			Struct l1__tmp = l0_result;
			switch (l1__tmp.getTypeId()) {
			case 105/*Some*/: {
				final Struct_Some l2__tmp = (Struct_Some)l1__tmp;
				final Object l3__value_ = l2__tmp.f_value;
				final Struct_ArRat l4__value_ = ((Struct_ArRat)l2__tmp.f_value);
				return Module_runtime.f_println(l4__value_);
			}
			case 44/*None*/: {
				return Module_runtime.f_println(Module_ex7.g_INVALID_INPUT);
			}
			default:
				throw new RuntimeException("Unexpected struct in switch: "+l1__tmp.getTypeName());
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
	public static final Struct_ArRat f_varLookup(String avariable, Object[] avariables) {
			final Struct_ArRat l2_$1 = (new Struct_ArRat(0, 0));
			final String l4_variable = avariable;
			final Func2<Struct_ArRat,Struct_ArRat, Struct_Pair> l3_$0 = (Func2<Struct_ArRat, Struct_ArRat, Struct_Pair>)(Struct_ArRat aacc, Struct_Pair acur_pair) -> {
				if ((((String)Module_tuples.f_firstOfPair(acur_pair))).equals(l4_variable)) {
					return (new Struct_ArRat(((Struct_ArRat)Module_tuples.f_secondOfPair(acur_pair)).f_num, ((Struct_ArRat)Module_tuples.f_secondOfPair(acur_pair)).f_denum));
				} else {
					return aacc;
				}
			};
			return ((Struct_ArRat)Native.fold(avariables, l2_$1, ((Func2<Object,Object, Object>)(Func2)l3_$0)));
		}
}
