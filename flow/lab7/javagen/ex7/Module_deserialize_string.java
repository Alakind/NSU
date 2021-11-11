// HASH COLLISIONS: YES
// timestamp: 1.636450864E12

package ex7;

import com.area9innovation.flow.*;

@SuppressWarnings("unchecked")
final class Module_deserialize_string {
	public static final Struct_Pair f_deserializeRestOfString2(String as, int astart) {
			return Module_deserialize_string.f_deserializeRestOfStringTail(as, astart);
		}
	public static final Struct_Pair f_deserializeRestOfStringTail(String as, int astart) {
			final Struct_Pair l0_rv = Module_deserialize_string.f_deserializeRestOfStringTail2(as, Module_list.f_makeList(), astart);
			return (new Struct_Pair(Module_string.f_cloneString(Native.list2string(((Struct)l0_rv.f_first))), l0_rv.f_second));
		}
	public static final Struct_Pair f_deserializeRestOfStringTail2(String as, Struct aacc, int astart) {
		TAIL_CALL: for(;;) {
			final int l0_strLength = Native.strlen(as);
			final int l1_quote = Native.strRangeIndexOf(as, "\"", astart, l0_strLength);
			final int l2_escape = Native.strRangeIndexOf(as, "\\", astart, l1_quote);
			if (((l2_escape!=(-1))&&(l2_escape<l1_quote))) {
				final String l3_first = Native.substring(as, astart, (l2_escape-astart));
				final int l4_escapedCharCode = Native.getCharCodeAt(as, (l2_escape+1));
				if ((l4_escapedCharCode==34)) {
					{
						final Struct l5___tmp = (new Struct_Cons("\"", (new Struct_Cons(l3_first, aacc))));
						final int l6___tmp = (l2_escape+2);
						aacc = l5___tmp;
						astart = l6___tmp;
						continue TAIL_CALL;
					}
				} else {
					if ((l4_escapedCharCode==92)) {
						{
							final Struct l7___tmp = (new Struct_Cons("\\", (new Struct_Cons(l3_first, aacc))));
							final int l8___tmp = (l2_escape+2);
							aacc = l7___tmp;
							astart = l8___tmp;
							continue TAIL_CALL;
						}
					} else {
						if ((l4_escapedCharCode==110)) {
							{
								final Struct l9___tmp = (new Struct_Cons("\n", (new Struct_Cons(l3_first, aacc))));
								final int l10___tmp = (l2_escape+2);
								aacc = l9___tmp;
								astart = l10___tmp;
								continue TAIL_CALL;
							}
						} else {
							if ((l4_escapedCharCode==117)) {
								final String l11_hex = Native.substring(as, (l2_escape+2), 4);
								final int l12_code = Module_string.f_parseHex(l11_hex);
								{
									final Struct l13___tmp = (new Struct_Cons(Native.fromCharCode(l12_code), (new Struct_Cons(l3_first, aacc))));
									final int l14___tmp = (l2_escape+6);
									aacc = l13___tmp;
									astart = l14___tmp;
									continue TAIL_CALL;
								}
							} else {
								if ((l4_escapedCharCode==120)) {
									final String l15_hex = Native.substring(as, (l2_escape+2), 2);
									final int l16_code = Module_string.f_parseHex(l15_hex);
									{
										final Struct l17___tmp = (new Struct_Cons(Native.fromCharCode(l16_code), (new Struct_Cons(l3_first, aacc))));
										final int l18___tmp = (l2_escape+4);
										aacc = l17___tmp;
										astart = l18___tmp;
										continue TAIL_CALL;
									}
								} else {
									String l19_descaped;
									if ((l4_escapedCharCode==116)) {
										l19_descaped="\t";
									} else {
										if ((l4_escapedCharCode==114)) {
											l19_descaped="\r";
										} else {
											l19_descaped=Native.fromCharCode(l4_escapedCharCode);
										}
									}
									{
										final Struct l20___tmp = (new Struct_Cons(l19_descaped, (new Struct_Cons(l3_first, aacc))));
										final int l21___tmp = (l2_escape+2);
										aacc = l20___tmp;
										astart = l21___tmp;
										continue TAIL_CALL;
									}
								}
							}
						}
					}
				}
			} else {
				if ((l1_quote==(-1))) {
					return (new Struct_Pair((new Struct_Cons(((astart>=l0_strLength)?"":Native.substring(as, astart, (l0_strLength-astart))), aacc)), l0_strLength));
				} else {
					return (new Struct_Pair((new Struct_Cons(Native.substring(as, astart, (l1_quote-astart)), aacc)), (l1_quote+1)));
				}
			}
		}
		}
	public static final Struct_Pair f_deserializeString(String as) {
			final Struct_Pair l0_rv = Module_deserialize_string.f_deserializeString2(as, 0);
			return (new Struct_Pair(l0_rv.f_first, Module_string.f_strRight(as, ((int)l0_rv.f_second))));
		}
	public static final Struct_Pair f_deserializeString2(String as, int astart) {
			if ((Native.substring(as, astart, 2)).equals("\"\"")) {
				return (new Struct_Pair("", (astart+2)));
			} else {
				if ((Native.getCharCodeAt(as, astart)==34)) {
					return Module_deserialize_string.f_deserializeRestOfStringTail(as, (astart+1));
				} else {
					return Module_deserialize_string.f_deserializeRestOfStringTail(as, astart);
				}
			}
		}
}
