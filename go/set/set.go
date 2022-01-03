package set

type Set struct {
	class map[interface{}]struct{}
}

func NewSet() *Set {
	s := &Set{
		class: make(map[interface{}]struct{}),
	}
	return s
}

// Push
func (s *Set) Push(id int, name string) bool {
	if _, ok := s.class[id]; ok {
		return false
	}
	s.class[id] = struct{}{}
	return true
}

// GetNames
func (s *Set) GetNames() []interface{} {
	names := make([]interface{}, 0, len(s.class))
	for l, _ := range s.class {
		names = append(names, l)
	}
	return names
}
