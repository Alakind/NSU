// HASH COLLISIONS: YES
// timestamp: 1.636517114374E12

package ex7;

import com.area9innovation.flow.*;

public class Struct_JsonString extends Struct {
	public String f_s;

	public Struct_JsonString() {}
	public Struct_JsonString(String a_s) {
		f_s = a_s;
	}

	public int getTypeId() { return 38; }
	public String getTypeName() { return "JsonString"; }

	private static final String[] field_names = new String[] {
		"s"
	};
	private static final RuntimeType[] field_types = new RuntimeType[] {
		RuntimeType.STRING
	};
	public String[] getFieldNames() { return field_names; }
	public RuntimeType[] getFieldTypes() { return field_types; }

	public Object[] getFields() {
		return new Object[] {
			f_s
		};
	}
	@SuppressWarnings("unchecked")
	public void setFields(Object[] values) {
		if (values.length != 1)
			throw new IndexOutOfBoundsException("Invalid field count in JsonString");
		f_s = (String)values[0];
	}

	public int compareTo(Struct other_gen) {
		if (other_gen == this) return 0;
		int tmp = other_gen.getTypeId();
		if (tmp != 38) return 38-tmp;
		Struct_JsonString other = (Struct_JsonString)other_gen;
		tmp = f_s.compareTo(other.f_s);
		return tmp;
	}
}
