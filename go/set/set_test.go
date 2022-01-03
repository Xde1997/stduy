package set

import "testing"

func TestPush(t *testing.T) {
	s := NewSet()
	var (
		in       = 3
		expected = true
	)
	actual := s.Push(in, "")
	if actual != expected {
		t.Errorf("s.Push(%d)=%t,expected=%t", in, actual, expected)
	}
}
