project('lol', 'c', default_options: ['c_std=c11'])

object_so = shared_library('object',
  'object_impl.c',
  name_prefix: '',
)

object_dep = declare_dependency(link_with: object_so)

executable('main',
  sources: [
    'main.c',
    'object.c',
  ],
  dependencies: [object_dep],
)
